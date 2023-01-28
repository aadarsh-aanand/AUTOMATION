#include <Arduino.h>
#include <Servo.h>
int fan = 2;
int light = 3;
Servo myservo;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, INPUT);
  myservo.attach(10);
  Serial.println("Welcome to homeAutomation simulation");
  myservo.write(0);
}

void loop()
{
  Serial.println("********************************");
  Serial.println("Enter 1 to turn on Fan");
  Serial.println("Enter 2 to turn off Fan");
  Serial.println("Enter 3 to turn on Light");
  Serial.println("Enter 4 to turn off Light");
  Serial.println("Enter 5 to turn on  Gate");
  Serial.println("Enter 6 to turn off Gate");
  Serial.println("Enter 7 to turn on all the devices");
  Serial.println("Enter 8 to turn off all the devices");
  Serial.println("********************************");
  while (Serial.available() == 0)
  {
  }
  int value = Serial.parseFloat();
  Serial.println(value);
  switch (value)
  {
  case 1:
    digitalWrite(fan, HIGH);
    Serial.println("Fan is turned ON");
    break;
  case 2:
    digitalWrite(fan, LOW);
    Serial.println("Fan is turned OFF");
    break;
  case 3:
    digitalWrite(light, HIGH);
    Serial.println("Light is turned ON");
    break;
  case 4:
    digitalWrite(light, LOW);
    Serial.println("Light is turned OFF");
    break;
  case 5:
    myservo.write(90);
    Serial.println("Gate is turned ON");
    break;
  case 6:
    myservo.write(0);
    Serial.println("Gate is turned OFF");
    break;
  case 7:
    Serial.println("All devices ON");
    digitalWrite(fan, HIGH);
    digitalWrite(light, HIGH);
    myservo.write(90);
    break;
  case 8:
    Serial.println("All devices are OFF");
    digitalWrite(fan, LOW);
    digitalWrite(light, LOW);
    myservo.write(2);
    break;
  default:
    Serial.println("enter the correct number");
    break;
  }
}