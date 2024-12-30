//These pin control the 2 motors on the right side of the car
int rightMotorPin1=16; //Control going forward
int rightMotorPin2=17; //Control going backward

//These pin control the 2 motors on the left side of the car
int leftMotorPin1=18; //Control going forward
int leftMotorPin2=19; //Control going backward
   
void setup() 
{ 
 // Set these pin to output mode to control the motor driver
 pinMode(rightMotorPin1, OUTPUT); 
 pinMode(rightMotorPin2, OUTPUT); 
 pinMode(leftMotorPin1, OUTPUT); 
 pinMode(leftMotorPin2, OUTPUT); 
} 
   
void loop() 
{ 
 // Rotate the 2 motors on the right to move forward
 digitalWrite(rightMotorPin1, HIGH); 
 digitalWrite(rightMotorPin2, LOW); 
 delay(2000); //2 seconds delay before the next test

 // Rotate the 2 motors on the right to move backward
 digitalWrite(rightMotorPin1, LOW); 
 digitalWrite(rightMotorPin2, HIGH); 
 delay(2000); 
  
 // Rotate the 2 motors on the left to move forward
 digitalWrite(leftMotorPin1, HIGH); 
 digitalWrite(leftMotorPin2, LOW); 
 delay(2000); 

 // Rotate the 2 motors on the left to move forward
 digitalWrite(leftMotorPin1, LOW); 
 digitalWrite(leftMotorPin2, HIGH); 
 delay(2000);
}