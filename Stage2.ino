#include <pwmWrite.h>

int analogSensorPinL = 27;
int analogSensorPinR = 25;

Pwm pwm = Pwm();

int rightServoPin = 13;
int leftServoPin = 14;

void setup() {
  Serial.begin(9600); // Start COM link from board -> computer

  pinMode(analogSensorPinL, INPUT); // Tell Board it has the analog sensor pin connect to it PIN LEFT
  pinMode(analogSensorPinR, INPUT); // Tell Board it has the analog sensor pin connect to it PIN RIGHT

  int sensorReadingTotal = 0;

  //collect 10 samples and average
  for(int i = 0; i <= 10; i++){ //for loop going from zero to ten in steps of one
    //read sensor and store
    int SensorReading = analogRead(analogSensorPinL + analogSensorPinR);
    //add to total
    sensorReadingTotal += SensorReading;
    //display current reading with labeled index
    Serial.print(i);
    Serial.print(" Reading - ");
    Serial.println(SensorReading);
    delay(50);

  /* pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500); 
  delay(2000); */

  }


  //calculate and display the average
  Serial.print("Average Reading - ");
  Serial.println(sensorReadingTotal/10.0);
}




void loop() {
  // put your main code here, to run repeatedly:

  
 // Serial.print("Output \t Left \t Right");// + analogRead(27)/10.0);
  // Serial.print("\t %.2f \t %.2f", analogRead(27), analogRead(23));
  Serial.println(analogRead(27)/10.0);
  Serial.print("Analog output - RIGHT - ");// + analogRead(23)/10.0);
  Serial.println(" ");
  Serial.println(analogRead(25)/10.0);
  Serial.print("Analog output - LEFT - ");// + analogRead(23)/10.0);
  delay(4000);

} // loop function to test analog output in Serial Monitor



/* void forward(){
  pwm.writeServo(rightServoPin, 1800);
  pwm.writeServo(leftServoPin, 1200);
  delay(2000);
  //forward drive
  pwm.writeServo(rightServoPin, 1500);
  pwm.writeServo(leftServoPin, 1500);
  delay(2000);
  //stop
} 

  servo.detach(); */
