# Motor drive design and implementation for two wheels robot base

## The Main Idea: 

The idea of this task is to connect the electronic circuit using Arduino, dc motors, h-bridge, and potentiometer ithat required for the wheels of the robotic arm.

![Screenshot_41](https://user-images.githubusercontent.com/85455361/122941593-3268c880-d37e-11eb-8f83-43d98ff14e2b.jpg)

## Components: 

1. Arduino UNO 

    ![Screenshot_43](https://user-images.githubusercontent.com/85455361/122953291-4533cb00-d387-11eb-9bcc-5deb9e6d51e9.jpg)

2. Two DC motors
    
    ![Screenshot_45](https://user-images.githubusercontent.com/85455361/122951410-ee79c180-d385-11eb-913f-b0a64a1b7d04.jpg)
    


3. Battery of 9 volts

    ![Screenshot_43](https://user-images.githubusercontent.com/85455361/122951453-f76a9300-d385-11eb-89e4-8a57882a3680.jpg)

4. H-bridge L293D

      Since I am using TINKERCAD then I can only use the L293D bridge as shown below
     
      ![Screenshot_44](https://user-images.githubusercontent.com/85455361/122951219-cab67b80-d385-11eb-9b52-efb332497135.jpg)

      and these are pins of the L293D chip 
 
      ![L293D-Motor-driver](https://user-images.githubusercontent.com/85455361/122951245-cf7b2f80-d385-11eb-90fe-442ba67a5603.jpg)

      
5. Potentiometer 

      I added the potentiometer to have the ability to control the speed of the dc motors

      ![Screenshot_46](https://user-images.githubusercontent.com/85455361/122951830-40224c00-d386-11eb-9b16-61e027749b4b.jpg)
      
## Connection Figure:

![Second Task - Motor drive design and implementation for two-wheel robot base (1)](https://user-images.githubusercontent.com/85455361/122953441-64325d00-d387-11eb-8d06-b315833fa1e9.png)


## Vedio:


https://user-images.githubusercontent.com/85455361/122956832-06ebdb00-d38a-11eb-9c33-47c11f0ab0c4.mp4

### Explain the vedio: 
   The explanation would be summrized in points:
   
   1. The speed of the dc motors controlled by the potentiometer.
   2. The above dc motor must be in the opposite direction of the below dc motor in the purpose of moving in the same direction. ( one is rotating clockwise while the other rotating counterclockwise).
   
## Code Explanation:

   Setting up: 
    
``` c++
//inputs of the two motors
int DcMotorA1=5;
int DcMotorA2=6;
int DcMotorB1=9;
int DcMotorB2=10;
 
//Potentiometer
int pot=A0; 
```
   Defining the inputs and outputs:
   
``` c++
  pinMode(DcMotorA1, OUTPUT);
  pinMode(DcMotorA2, OUTPUT);
  pinMode(DcMotorB1, OUTPUT);
  pinMode(DcMotorB2, OUTPUT);
  pinMode(pot, INPUT);
```
  Programming the DC motors to be controlled (speed) by the potentiometer

``` c++
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
  
  else 	  	// Backward
  {
    speed = map(analogRead(pot), 512, 0, 0, 255);
    analogWrite(DcMotorA1, speed);
    analogWrite(DcMotorA2, 0);
    analogWrite(DcMotorB1, 0);
    analogWrite(DcMotorB2, speed);
  }
  
```


## Suggest an Extra Idea:
    
  Let each dc motor be controlled by a separate potentiometer in the purpose of turning instead of only forward and backward moves
  
  
  ![Second Task - Motor drive design and implementation for two-wheel robot base (1)](https://user-images.githubusercontent.com/85455361/122960592-3865a600-d38c-11eb-9eeb-9565e3e15e30.png)


