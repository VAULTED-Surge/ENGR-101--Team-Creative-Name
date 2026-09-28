#include <ESP32Servo.h>

Servo myServo;

void setup() {

  myServo.attach(14);     // Change 14 to your servo signal pin

}

void loop() {

    myServo.write(0);     // Rotate wheel servo to a 0-degree positon
    delay(1000);          // Wait 1 second
    myServo.write(90);    // Rotate wheel servo to a 90-degree position
    delay(1000);          // Wait 1 second
    myServo.write(180);   // Rotate wheel servo to a 180-degree position
    delay(1000);          // Wait 1 second

}