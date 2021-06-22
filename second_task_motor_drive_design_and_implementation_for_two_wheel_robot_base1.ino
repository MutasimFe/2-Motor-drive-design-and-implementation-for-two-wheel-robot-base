// c++
// DC motors controlled by potentiometer 

//inputs of the two motors
int DcMotorA1=5;
int DcMotorA2=6;
int DcMotorB1=9;
int DcMotorB2=10;
 
//Potentiometer
int pot=A0; 


void setup()
{
 
  pinMode(DcMotorA1, OUTPUT);
  pinMode(DcMotorA2, OUTPUT);
  pinMode(DcMotorB1, OUTPUT);
  pinMode(DcMotorB2, OUTPUT);
  pinMode(pot, INPUT);
  
}

void loop()
{
  
  int speed;
  speed = analogRead(pot);
  
  if(speed >= 512) // Forward
  {
    
    speed = map(analogRead(pot), 512, 1023, 0, 255);
    analogWrite(DcMotorA1, 0);
    analogWrite(DcMotorA2, speed);
    analogWrite(DcMotorB1, speed);
    analogWrite(DcMotorB2, 0);
   
  }
  
  else 				// Backward
  {
    speed = map(analogRead(pot), 512, 0, 0, 255);
    analogWrite(DcMotorA1, speed);
    analogWrite(DcMotorA2, 0);
    analogWrite(DcMotorB1, 0);
    analogWrite(DcMotorB2, speed);
  }
  
  
}