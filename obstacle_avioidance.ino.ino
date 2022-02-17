#include <Servo.h>
Servo myservo;
int pos1=0;
int trig=7;
int i=0;
int echo=6;
int led=13;

int inputPin1  = 10;   
int inputPin2  = 11; 
int inputPin3  = 9;  
int inputPin4  = 8;

int distance,duration;
int d,dr,dl;

//*********************************//
int sensor()
{
   Serial.print("  Entered sensor function .");
   digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance= duration*0.034/2;

  return distance;
   Serial.print("Distance is :");
   Serial.print(distance);
   Serial.print("  sensor function completed .");
   
}


void mstop()
{
     Serial.print(" Entered mstop function .");
     digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, HIGH);
     Serial.print(" mstop function completed . ");  
}


void mback()
{
    
     Serial.print(" Entered mback .");
     digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, LOW); 
    Serial.print(" excicuted mback ."); 
}


int lookright()
{
    Serial.print(" Entered lookright function .");
    myservo.write(0); 
    delay(500);
    int dist = sensor();
    delay(100);
    Serial.print(" Right distance is : ");
    Serial.print(dist); 
    return dist;
    
    
}

int lookleft()
{
    Serial.print(" Entered lookleft .");
    myservo.write(180); 
    delay(500);
    int dist = sensor();
    delay(100);
    delay(1000);
    myservo.write(90);
    Serial.print(" Left distance is : ");
    Serial.print(dist); 
    return dist;
}

void turnright()
{
    Serial.print(" Entered turnright .");
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, HIGH);
    delay(500);
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, HIGH);
    Serial.print(" excicuted turnright .");  
}

void turnleft()
{
    Serial.print(" Entered turnleft .");
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, HIGH);
    delay(500);
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, HIGH);
    Serial.print(" excicuted turnright .");  
}

void mforward()
{
    Serial.print(" Entered mforward .");
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, HIGH);
    Serial.print(" mforward function complete ."); 
   
}



//********************************//
void setup()
{
  myservo.attach(5);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  pinMode(led, OUTPUT);

    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);  
    pinMode(2,OUTPUT);
    digitalWrite(2,HIGH);
   
  Serial.begin(9600);
  Serial.print("Setup Complete"); 
}

void loop()
{
   Serial.print(" Entered to Loop .");
   mforward();
   d= sensor();
  if(d<15)
  {
    Serial.print( " Entered if condition .");
    mstop();
    delay(1000);
    mback();
    delay(400);
    mstop();
    dr=lookright();
    Serial.print(" Looked right .");
    delay(500);
    dl=lookleft();
    Serial.print(" Looked left .");
    
    delay(2000);

    if(dr>dl)
    {
      Serial.print(" When right distance is greater , Turning right .");
      mforward();
      delay(50);
      turnright();
      Serial.print(" Moving forward .");
      mforward();
    }
    if(dl>dr)
    {
      Serial.print(" When left distance is greater , Turning left .");
      mforward();
      delay(50);
      turnleft();
      Serial.print(" Moving forward .");
      mforward();
    }
    
  }
  
  else
  {
    Serial.print(" Enetered else condition .");
    Serial.print(" Moving forward .");
    mforward();
  }

}
