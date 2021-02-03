#Function: Outside_wheel_speed = S * ((R + (Vehicle_Wdith / 2)) * 2 * pi)/(R * 2 * pi) Inside_wheel_speed = S * ((R - (Vehicle_Wdith / 2)) * 2 * pi)/(R * 2 * pi) Return

int S = 150;
int R = scale*12;
int W = 6;
int vL = S*((R-(W/2))*2*3.14)/(R*2*3.14);
int vR = S*((R+(W/2))*2*3.14)/(R*2*3.14);
fLeft->setSpeed(vL);
bLeft->setSpeed(vL);
fRight->setSpeed(vR);
bRight->setSpeed(vR);
forward(scale);

#include <Wire.h>
#include <Adafruit_MotorShield.h>
 
// Create the motor shield object
Adafruit_MotorShield shield = Adafruit_MotorShield(); 
 
// Assign names to motors
Adafruit_DCMotor *bLeft = shield.getMotor(1);
Adafruit_DCMotor *bRight = shield.getMotor(2);
Adafruit_DCMotor *fLeft = shield.getMotor(4);
Adafruit_DCMotor *fRight = shield.getMotor(3);
 
void setup(){
  Serial.begin(9600);
  //Start motor shield object with default frequency (1.6KHz)
  shield.begin();
  //Set speed of the motors
  bLeft->setSpeed(150);
  bRight->setSpeed(150);
  fLeft->setSpeed(150);
  fRight->setSpeed(150);
}
 
/* MOVE FORWARD */
void forward(float scale){
  //Distance variable = speed*scale
  float d = 150*scale;
  //Move for specified distance
  for (int i = 0; i < d; i++){
  bLeft->run(FORWARD);
  bRight->run(FORWARD);
  fLeft->run(FORWARD);
  fRight->run(FORWARD);
  }
  //Stop Moving
  bLeft->run(RELEASE);
  bRight->run(RELEASE);
  fLeft->run(RELEASE);
  fRight->run(RELEASE);
}
 
/* MOVE BACKWARD */
void backward(float scale){
  //Distance variable = speed*scale
  float d = 150*scale;
  //Move for specified distance
  for (int i = 0; i < d; i++){
  bLeft->run(BACKWARD);
  bRight->run(BACKWARD);
  fLeft->run(BACKWARD);
  fRight->run(BACKWARD);
  }
  //Stop Moving
  bLeft->run(RELEASE);
  bRight->run(RELEASE);
  fLeft->run(RELEASE);
  fRight->run(RELEASE);
}
 
/* ROTATE LEFT */
void rotLeft(int degree){
  //Right wheels forward and left wheels backward to make
  //a left turn
  for (int i = 0; i < degree*2; i++){
    //degree*2 was determined to be the best amount of time for
    //accurate degree rotation
    fRight->run(FORWARD);
    bRight->run(FORWARD);
    fLeft->run(BACKWARD);
    bLeft->run(BACKWARD);
  }
  //Stop turning wheels
  bLeft->run(RELEASE);
  bRight->run(RELEASE);
  fLeft->run(RELEASE);
  fRight->run(RELEASE);
}
 
/* ROTATE RIGHT */
void rotRight(int degree){
  //Right wheels backward and left wheels forward to make
  //a right turn
  for (int i = 0; i < degree*2; i++){
    //degree*2 was determined to be the best amount of time for
    //accurate degree rotation
    fRight->run(BACKWARD);
    bRight->run(BACKWARD);
    fLeft->run(FORWARD);
    bLeft->run(FORWARD);
  }
  //Stop turning wheels
  bLeft->run(RELEASE);
  bRight->run(RELEASE);
  fLeft->run(RELEASE);
  fRight->run(RELEASE);
}
 
/* MOVE LEFT */
void goLeft(float scale){
  //Rotate left 90 degrees
  rotLeft(90);
  //Move <scale> feet forward
  forward(scale);
}
 
/* MOVE RIGHT */
void goRight(float scale){
  //Rotate right 90 degrees
  rotRight(90);
  //Move <scale> feet forward
  forward(scale);
}
 
/* MAKE A CIRCLE TO THE LEFT WITH RADIUS <scale> */
void cLeft(float scale){
  float lMod = (scale*0.12)*250;
  bLeft->setSpeed(lMod);
  fLeft->setSpeed(lMod);
}
 
/* MAKE A CIRCLE TO THE RIGHT WITH RADIUS <scale> */
void cRight(float scale){
  float rMod = (scale*0.15)*250;
  bRight->setSpeed(rMod);
  fRight->setSpeed(rMod);
}
 
void loop(){
  //Scale in feet
  int s = 1;
  cLeft(s);
 
  bLeft->run(FORWARD);
  bRight->run(FORWARD);
  fLeft->run(FORWARD);
  fRight->run(FORWARD);
  //Stop Moving
  bLeft->run(RELEASE);
  bRight->run(RELEASE);
  fLeft->run(RELEASE);
  fRight->run(RELEASE);
}