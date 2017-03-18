#include "L3G4200D.h"

bool L3G4200D::begin(l3g4200d_dps_t scale, l3g4200d_odrbw_t odrbw) {
  // Reset calibrate values
  for(int i = 0; i<3; i++) delta[i]=0;
  useCalibrate = false;

  // Reset threshold values
  for(int i = 0; i<3; i++) threshold[i]=0;
  actualThreshold = 0;

  Wire.begin();

  // Check L3G4200D Who Am I Register
  if (fastRegister8(WHO_AM_I) != 0xD3) return false;

  // Enable all axis and setup normal mode + Output Data Range & Bandwidth
  byte reg1 = 0x00;
  reg1 |= 0x0F; // Enable all axis and setup normal mode
  reg1 |= (odrbw << 4); // Set output data rate & bandwidh
  writeRegister8(CTRL_REG1, reg1);

  // Disable high pass filter
  writeRegister8(CTRL_REG2, 0x00);

  // Generata data ready interrupt on INT2
  writeRegister8(CTRL_REG3, 0x08);

  // Set full scale selection in continous mode
  writeRegister8(CTRL_REG4, scale << 4);

  switch (scale) {
    case L3G4200D_SCALE_250DPS:
      dpsPerDigit = .00875f;
      break;
    case L3G4200D_SCALE_500DPS:
      dpsPerDigit = .0175f;
      break;
    case L3G4200D_SCALE_2000DPS:
      dpsPerDigit = .07f;
      break;
    default:
      break;
  }

  // Boot in normal mode, disable FIFO, HPF disabled
  writeRegister8(CTRL_REG5, 0x00);

  return true;
}

// Get current scale
l3g4200d_dps_t L3G4200D::getScale() {
  return (l3g4200d_dps_t)((readRegister8(CTRL_REG4) >> 4) & 0x03);
}

// Get current output data range and bandwidth
l3g4200d_odrbw_t L3G4200D::getOdrBw() {
  return (l3g4200d_odrbw_t)((readRegister8(CTRL_REG1) >> 4) & 0x0F);
}

// Calibrate algorithm
void L3G4200D::calibrate(byte samples) {
  // Set calibrate
  useCalibrate = true;

  // Reset values
  float sum[3];
  for(int i = 0; i<3; i++) sum[i]=0;
  float sigma[3];
  for(int i = 0; i<3; i++) sigma[i]=0;

  // Read n-samples
  for (byte i = 0; i < samples; ++i) {
    readRaw();
	for(int i = 0; i<3; i++) sum[i]+=raw[i];
	for(int i = 0; i<3; i++) sigma[i] += raw[i] * raw[i];
    delay(5);
  }

  // Calculate delta vectors
  for(int i = 0; i<3; i++) delta[i] = sum[i]/samples;

  // Calculate threshold vectors
  for(int i = 0; i<3; i++) threshold[i] = sqrt((sigma[i] / samples) - (delta[i] * delta[i]));

  // If already set threshold, recalculate threshold vectors
  if (actualThreshold > 0) {
    setThreshold(actualThreshold);
  }
}

// Get current threshold value
byte L3G4200D::getThreshold() {
  return actualThreshold;
}

// Set treshold value
void L3G4200D::setThreshold(byte multiple) {
  if (multiple > 0) {
    // If not calibrated, need calibrate
    if (!useCalibrate) calibrate();

    // Calculate threshold vectors
    for(int i = 0; i<3; i++) threshold[i] *= multiple;
  }
  else {
    // No threshold
    for(int i = 0; i<3; i++) threshold[i]=0;
  }

  // Remember old threshold value
  actualThreshold = multiple;
}

// Write 8-bit to register
void L3G4200D::writeRegister8(byte reg, byte value) {
  Wire.beginTransmission(ADDRESS);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
}

// Fast read 8-bit from register
byte L3G4200D::fastRegister8(byte reg) {
  byte value;

  Wire.beginTransmission(ADDRESS);
  Wire.write(reg);
  Wire.endTransmission();

  Wire.beginTransmission(ADDRESS);
  Wire.requestFrom(L3G4200D_ADDRESS, 1);
  value = Wire.read();
  Wire.endTransmission();

  return value;
}

// Read 8-bit from register
byte L3G4200D::readRegister8(byte reg) {
  byte value;

  Wire.beginTransmission(ADDRESS);
  Wire.write(reg);
  Wire.endTransmission();

  Wire.beginTransmission(ADDRESS);
  Wire.requestFrom(ADDRESS, 1);
  while (!Wire.available()) {};
  value = Wire.read();
  Wire.endTransmission();

  return value;
}

// L3G4200D Temperature sensor output change vs temperature: -1digit/degrCelsius (data representation: 2's complement).
// Value represents difference respect to a reference not specified value.
// So temperature sensor can be used to measure temperature variations: temperarture sensor isn't suitable to return absolute temperatures measures.
// If you run two sequential measures and differentiate them you can get temperature variation.
// This also means that two devices in the same temp conditions can return different outputs.
// Finally, you can use this info to compensate drifts due to temperature changes.
byte L3G4200D::readTemperature() {
  return readRegister8(OUT_TEMP);
}


void L3G4200D::readRaw() {
  Wire.beginTransmission(ADDRESS);
  Wire.write(OUT | (1 << 7));
  Wire.endTransmission();
  Wire.requestFrom(ADDRESS, 6);

  while (Wire.available() < 6);

  byte xla = Wire.read();
  byte xha = Wire.read();
  byte yla = Wire.read();
  byte yha = Wire.read();
  byte zla = Wire.read();
  byte zha = Wire.read();

  raw[0] = xha << 8 | xla;
  raw[1] = yha << 8 | yla;
  raw[2] = zha << 8 | zla;
}

void L3G4200D::read() {
  readRaw();
  if (useCalibrate) {
    x = (raw[0] - delta[0]) * dpsPerDigit;
    y = (raw[1] - delta[1]) * dpsPerDigit;
    z = (raw[2] - delta[2]) * dpsPerDigit;
  }
  else{
    x = raw[0] * dpsPerDigit;
    y = raw[1] * dpsPerDigit;
    y = raw[2] * dpsPerDigit;
  }
  if (actualThreshold > 0) {
    if (abs(x) < threshold[0]) x = 0;
    if (abs(y) < threshold[1]) y = 0;
    if (abs(z) < threshold[2]) z = 0;
  }
}
