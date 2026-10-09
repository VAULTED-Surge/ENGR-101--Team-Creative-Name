
#include <pwmWrite.h>

// Define separate pins for your two servos
// team creative name stage 1 code 
/*
After attempting 2 seperate uploads both created different results */
Pwm pwm = Pwm();

int rightServoPin = 13;
int leftServoPin = 14;

void setup() {
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  delay(2000);
  forward();
  reverse();
  forward();
  rightturn45();
  rightturn45();
  rReset();
  rReset();
  leftturn45();
  leftturn45(); 
  lReturn();
  lReturn();
  
}// end of setup function

void loop() {
  // put your main code here, to run repeatedly:
  
}

void forward(){
  pwm.writeServo(rightServoPin, 1800);
  pwm.writeServo(leftServoPin, 1200);
  delay(2000);
  //forward drive
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  delay(2000);
  //stop
}

void reverse(){
  pwm.writeServo(rightServoPin, 1400);
  pwm.writeServo(leftServoPin, 1600);
  delay(2000);
  //reverse
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  delay(2000);
  //stop
}

void rightturn45(){
  pwm.writeServo(rightServoPin, 1600);
  pwm.writeServo(leftServoPin, 1500);
  delay(1000);
  //reverse
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  delay(2000);
  //stop

}
void leftturn45(){
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1400);
  delay(1000);
  //reverse
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  delay(2000);
  //stop
}

void rReset(){
  pwm.writeServo(rightServoPin, 1400);
  pwm.writeServo(leftServoPin, 1500);
  delay(1000);
  //reverse
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  delay(2000);
  //stop
}

void lReturn(){
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1600);
  delay(1000);
  //reverse
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  delay(2000);
  //stop
}