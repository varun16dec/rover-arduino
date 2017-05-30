#include <AFMotor.h> //import motor shield library
#define trigPin 12 // define the pins of your sensor
#define echoPin 13
AF_DCMotor motor1(1,MOTOR12_64KHZ); // set up motors.
AF_DCMotor motor2(2, MOTOR12_8KHZ);
void setup() {
 Serial.begin(9600); // begin serial communication  
 Serial.println("Motor test!");
 pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
 pinMode(echoPin, INPUT);// set the echo pin to input (receive sound waves)
 motor1.setSpeed(105); //set the speed of the motors, between 0-255
 motor2.setSpeed (105);  
}
void loop() {
  long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // delays are required for a successful sensor operation.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimetres.
  if (distance < 25) /*if there's an obstacle 25 centimetres, ahead, do the      following: */ {   
  motor1.run(FORWARD);  // Turn as long as there's an obstacle ahead.
  motor2.run (BACKWARD);
}
 else {
  Serial.println ("No obstacle detected. going forward");
  delay (15);
  motor1.run(FORWARD); //if there's no obstacle ahead, Go Forward!
  motor2.run(FORWARD);
 }
}
