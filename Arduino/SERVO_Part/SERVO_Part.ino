#include <Servo.h> 

/////////////////////////////

Servo myservo;

boolean IsServoInitialed = false;

int servoPin = 9;
int ledPin = 13;


/////////////////////////////
//SETUP
void setup(){
  Serial.begin(9600);
  
  myservo.attach(servoPin);
  
  pinMode(ledPin, OUTPUT);
}

////////////////////////////
//LOOP
void loop(){

     if( Serial.available() > 0 )
     {
       char fromXbee = Serial.read();
       // fire condition check
       if (fromXbee == 'F' && IsServoInitialed)
       {
         digitalWrite(ledPin, HIGH);
         for(int pos = 0; pos < 120; pos += 1 ) 
       {                                  
           myservo.write(pos);
           delay(10);
       }
         delay(300);
         IsServoInitialed = false;
         // signal PC catapult is used!
         Serial.println(false);
       }
     }
     
     if (IsServoInitialed == false)
     {
       digitalWrite(ledPin, LOW);
       
       for(int pos = 90; pos > 0; pos -= 1 ) 
       {                                  
           myservo.write(pos);            
           delay(30);                     
       }
       IsServoInitialed = true;
       // signal to PC catapult is READY!
       Serial.println(true);
     }
  }
