#include <Servo.h>

// Initialize servo motors
Servo servo1;
Servo servo2;

//Left ultrasonic sensor (blue)
const int pingPin1 = 4; // Trigger Pin of Ultrasonic Sensor
const int echoPin1 = 5; // Echo Pin of Ultrasonic Sensor

//Middle ultrasonic sensor
const int pingPin2 = 6; // Trigger Pin of Ultrasonic Sensor
const int echoPin2= 7; // Echo Pin of Ultrasonic Sensor

//Right ultrasonic sensor (red)
const int pingPin3 = 2; // Trigger Pin of Ultrasonic Sensor
const int echoPin3 = 3; // Echo Pin of Ultrasonic Sensor

   
const int motorPin1 = 8;
//const int motorPin2 = 11;
//const int motorPin3 = 12;
//const int motorPin4 = 3;


void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   servo1.attach(9);
   servo2.attach(10);
   pinMode(motorPin1, OUTPUT);
}

void loop() {
   long duration1, inches1, cm1;
   long duration2, inches2, cm2;
   long duration3, inches3, cm3;
  
   pinMode(motorPin1, OUTPUT);
   //pinMode(motorPin2, OUTPUT);
   //pinMode(motorPin3, OUTPUT);
   //pinMode(motorPin4, OUTPUT);

   //Setup ultrasonic sensor 1
   setupUltrasonicSensor(pingPin1, echoPin1); 
   duration1 = pulseIn(echoPin1, HIGH);
   cm1 = microsecondsToCentimeters(duration1);
   Serial.print(cm1);
   Serial.print("cm left: ");
   Serial.println();

   //Setup ultrasonic sensor 2
   setupUltrasonicSensor(pingPin2, echoPin2);
   duration2 = pulseIn(echoPin2, HIGH);
   cm2 = microsecondsToCentimeters(duration2);
   Serial.print(cm2);
   Serial.print("cm middle: ");
   Serial.println();

   //Setup ultrasonic sensor 3
   setupUltrasonicSensor(pingPin3, echoPin3);
   duration3 = pulseIn(echoPin3, HIGH);
   cm3 = microsecondsToCentimeters(duration3);
   Serial.print(cm3);
   Serial.print("cm right: ");
   Serial.println();
   
 //  if(cm1>10)
      //digitalWrite(motorPin1, HIGH);
     // digitalWrite(motorPin3, LOW);
  // if(cm3>10)
//      digitalWrite(motorPin3, HIGH);
      //digitalWrite(motorPin1, LOW);
   //if(cm2>10)
//     digitalWrite(motorPin2, HIGH);
//    digitalWrite(motorPin4, HIGH);

digitalWrite(motorPin1, HIGH);
delay(2000);
   
   //Servos
   if (cm1 < 20 || cm2 < 20 || cm3 < 20) {
    servo1.write(90);
    servo2.write(90);
    delay(1);
   }
   else {
    servo1.write(180);
    servo2.write(180);
    delay(1);

}
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

void setupUltrasonicSensor(int pingPin, int echoPin) {
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
}
