
#include <pwmWrite.h>

// Define separate pins for your two servos
// team creative name stage 1 code 
/*
After attempting 2 seperate uploads both created different results */
Pwm pwm = Pwm();

int rightServoPin = 13;
int leftServoPin = 14;
int trigPin = 12; 
int echoPin = 35;//This is an input only pin
int RightanalogSensorPin = 25;//insert your pin values with respect to your wiring
int LeftanalogSensorPin = 27;
//defining value for color black
int blackRightside = 910; //update these values from your foundings
int blackLeftside = 910;

//defining servo movement variable, to be set in control logic
int RightMovement = 0;
int LeftMovement = 0;
//const int BLUE = 32;
//variables (Pins)
int R_pin = 32;
int G_pin = 33;
int B_pin = 25;


void setup() {
  //set the pinmode
  pinMode(R_pin, OUTPUT);
  pinMode(G_pin, OUTPUT);
  pinMode(B_pin, OUTPUT);

//write some voltage to the led
  analogWrite(R_pin, 50); //second value is ranged from 0 to 255
  analogWrite(G_pin, 150);
  analogWrite(B_pin, 50);
  //opening COM-port. 
  Serial.begin (9600);
  //telling the arduino it has stuff plugged into it and their mode. 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  //pinMode(BLUE, OUTPUT);
  //pinMode(RightanalogSensorPin, INPUT);
  //pinMode(LeftanalogSensorPin, INPUT);
  //setup for both ir and ultrasonic 
  
  //runs game start auton
  delay(5000);
  for (int i = 0; i< 2; i++){
    auton_forward();
  }
  for (int i = 0; i< 2; i++){
    auton_reverse();
  }

}// end of setup function

void loop() {
  //set servos to move at desired direction

  

  //defense algo
  // put your main code here, to run repeatedly:
  //variables
  long duration, distance;
  //trig the pulse required. 
  digitalWrite(trigPin, LOW);  //off
  delayMicroseconds(2); //the delays help produce a known signal. 
  digitalWrite(trigPin, HIGH); //on
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); //off
  //record the pulse in
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  //print the distance recorded. 
  Serial.println("-------------------------------------");
  Serial.print("Non-function usage -> ");
  Serial.print(distance/2.54); 
  Serial.println(" in");
  Serial.print("Function return -> ");
  Serial.print(DistanceREAD());
  Serial.println(" cm"); 
  
 
  //inserting a small delay for human eyes
  delay(200);
  if (distance/2.54 < 3){
    forward();
    reverse();
  }
  rightturn45();
  rReset();
  leftturn45();
  lReturn();
}

void forward(){
  pwm.writeServo(rightServoPin, 1800);
  pwm.writeServo(leftServoPin, 1200);
  delay(500);
  //forward drive
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  delay(500);
  //stop
}

void reverse(){
  pwm.writeServo(rightServoPin, 1400);
  pwm.writeServo(leftServoPin, 1600);
  delay(1000);
  //reverse
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  delay(1000);
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

//function format 
long DistanceREAD(){
 long duration;
  //trig the pulse required. 
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  //record the pulse in
  duration = pulseIn(echoPin, HIGH);
  return (duration/2) / 29.1;
  

}

void auton_forward(){
  pwm.writeServo(rightServoPin, 1800);
  pwm.writeServo(leftServoPin, 1200);
  delay(1000);
  //forward drive
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  delay(1000);
  //stop
}

void auton_reverse(){
  pwm.writeServo(rightServoPin, 1400);
  pwm.writeServo(leftServoPin, 1600);
  delay(1000);
  //reverse
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  delay(1000);
  //stop
}