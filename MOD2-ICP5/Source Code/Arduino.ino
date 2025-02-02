#include <Servo.h>
#define echoPin 12
#define trigPin 11

Servo lServo;
Servo rServo;
long duration;
long distance;
String str;
int blueToothVal;
//Serial.begin(115200);                  
//Serial1.begin(9600);

void setup() {
  Serial.begin(115200);                  
  Serial1.begin(9600);  
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  lServo.attach(9);
  rServo.attach(10);
}

void loop() {
digitalWrite(trigPin, LOW);
  delay(10);

  digitalWrite(trigPin, HIGH);
  delay(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.print('Ultrasound distance = ' + distance);  
  if(distance != 0){}
  else{
bluetooth();
};
}
void bluetooth()
{
 while (Serial1.available())                            
 {  
  {  
      str = Serial1.readStringUntil('\n');          
      //Serial.print(str);            
  }
   
    blueToothVal = (str.toInt());                  
    Serial.print("BlueTooth Value ");
    Serial.println(blueToothVal);    


 switch (blueToothVal)
 {
      case 1:                                
        Serial1.println("Forward");
        Forward();
        break;

      case 2:                
        Serial1.println("Reverse");
        Reverse();
        break;

      case 3:        
        Serial1.println("Left");
        LeftTurn();
        break;
       
      case 4:                    
        Serial1.println("Right");
        RightTurn();
        break;  

 }                                                            

 }                                                            
 
   if (Serial1.available() < 0)                              
    {
     Serial1.println("No Bluetooth Data ");          
    }
 
}

void Forward()
{
  Serial.println("Forward");
  lServo.write(100);
  rServo.write(100);
  delay(10);
  lServo.write(100);
  rServo.write(100);
  delay(100);
}


void Reverse()
{
  Serial.println("Reverse");
  lServo.write(100);
  rServo.write(100);
  delay(10);
  lServo.write(100);
  rServo.write(100);
  delay(100);
}


void LeftTurn()
{
  Serial.println("Left");
  lServo.write(100);
  rServo.write(5);
  delay(10);
  lServo.write(100);
  rServo.write(5);
  delay(100);
}


void RightTurn()
{
  Serial.println("Right");
  lServo.write(5);
  rServo.write(100);
  delay(10);
  lServo.write(5);
  rServo.write(100);
  delay(100);                                                              
}
