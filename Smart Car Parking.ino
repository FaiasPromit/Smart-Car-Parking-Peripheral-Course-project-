
#define trigPin 2
#define echoPin 3 // attach pin D2 Arduino to pin Echo of HC-SR04 //attach pin D3 Arduino to pin Trig of HC-SR04
#define redLight 4
#define greenLight 5
#define whiteLight 6
#define buzzer 7

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

#include<Servo.h>
Servo Myservo;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(redLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(whiteLight, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Myservo.attach(8);
  
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  if(distance <= 20 && distance > 10 )
  {
    digitalWrite(redLight, LOW);
    digitalWrite(greenLight, LOW);
    digitalWrite(whiteLight, HIGH);
    noTone(buzzer); // Send 1KHz sound signal...
    //delay(1000);
    Myservo.write(0);
    delay(15);
  }
  else if(distance <= 10 && distance > 5 )
  {
    digitalWrite(redLight, LOW);
    digitalWrite(greenLight, HIGH);
    noTone(buzzer);     // Stop sound...
    //delay(1000);        // ...for 1sec
    Myservo.write(90);
    delay(15);
  
  }
  else if(distance <= 5)
  {
    digitalWrite(redLight, HIGH);
    tone(buzzer, 200); // Send 1KHz sound signal...
    delay(1000);
  }
  else if(distance > 20)
  {
    noTone(buzzer);     // Stop sound...
    //delay(1000);        // ...for 1sec
    Myservo.write(90);
    delay(15);
    digitalWrite(redLight, LOW);
    //delay(1000);
    digitalWrite(greenLight, LOW);
    //delay(1000);
    digitalWrite(whiteLight, LOW);
    //delay(1000);
    noTone(buzzer);     // Stop sound...
    //delay(1000);        // ...for 1sec
  }
  


  
}
