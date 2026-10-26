#include <pwmWrite.h>

Pwm pwm = Pwm();

int RightanalogSensorPin = 25;//insert your pin values with respect to your wiring
int LeftanalogSensorPin = 27;

int rightServoPin = 13;//update these if need be. 
int leftServoPin = 14;

//defining value for color black
int blackRightside = 17.40; //update these values from your foundings
int blackLeftside = 21.40;


//defining servo movement variable, to be set in control logic
int RightMovement = 0;
int LeftMovement = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Start a COM link from the board to the compupter

  //Tell the board that it has something connected to it
  pinMode(RightanalogSensorPin, INPUT);
  pinMode(LeftanalogSensorPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  //read from both sensors and store
  int rightSensorReading = analogRead(RightanalogSensorPin);
  int leftSensorReading = analogRead(LeftanalogSensorPin);

  //control logic 
  if(rightSensorReading > blackRightside && leftSensorReading < blackLeftside){
    //set movement values
    RightMovement = 1550;
    LeftMovement = 1550;
  }
  if(rightSensorReading < blackRightside && leftSensorReading > blackLeftside){
    //set movement values
    RightMovement = 1450;
    LeftMovement = 1450;
  }
  if(rightSensorReading > blackRightside && leftSensorReading > blackLeftside){
    //set movement values
    RightMovement = 1450;
    LeftMovement = 1550;
  }

  //set servos to move at desired direction
  pwm.writeServo(rightServoPin, RightMovement);
  pwm.writeServo(leftServoPin, LeftMovement);
}
