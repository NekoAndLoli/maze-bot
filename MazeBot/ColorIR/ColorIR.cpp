#include "ColorIR.h"
ColorIR::ColorIR(){}

/**
 *@return 0 se sotto non c'è niente, 1 se c'è uno specchio e 2 se è nero.
 */
int ColorIR::surfaceType()  { 
  int media = analogRead(L_CIR);
  delay(100);
 media  += analogRead(R_CIR);
 media>>=1;
  return (media<=BLACK)?((media>=MIRROR)?1:0):2;
}
