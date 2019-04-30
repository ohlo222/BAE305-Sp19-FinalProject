
#include <Servo.h>

Servo myservo;
Servo myservotwo; // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;          // variable to store the servo position
int pos2 = 0;
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int motors = (9, 8);
int i = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservotwo.attach(8);
  pinMode(motors, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  if (sensorValue > 800 && i==0){
    digitalWrite(motors, HIGH);
    for (pos = 0; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      int pos2 = abs(pos - 180) ;
      myservo.write(pos);     // tell servo to go to position in variable 'pos'
      myservotwo.write(pos2);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 110; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      int pos2 = abs(pos - 180);
      myservo.write(pos);             // tell servo to go to position in variable 'pos'
      myservotwo.write(pos2);
      delay(15); // waits 15ms for the servo to reach the position
    }
    i=1;
    delay(64800000);
  }else {
    digitalWrite(motors, LOW);
    i=0;
    delay(5000);
}
}
