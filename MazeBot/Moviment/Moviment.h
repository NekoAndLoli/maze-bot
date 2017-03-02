#ifndef MOVIMENT_H
#define MOVIMENT_H

// defining constant pin for motors
#define R_EN 4
#define R_IN1 2
#define R_IN2 3
#define L_EN 7
#define L_IN1 6
#define L_IN2 5

#include <Arduino.h>
class Moviment {
  public:
    Moviment (int speed, int rightK, int leftK); 
    void go (bool invert);
    void rotate (bool invert);
    void stop();
  private:
    Motor motorR(R_EN,R_IN1,R_IN2);
    Motor motorL(L_EN,L_IN1,L_IN2);
  
    short speed = 80;
    short kR = 0;
    short kL = 0;
};
#endif
