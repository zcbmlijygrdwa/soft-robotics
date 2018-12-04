#include <math.h>

#include <Servo.h>
int top = 10;
int delayT = 60;
int frameCount = 0;

const int airPump1 = 9;    //Air pump motor with npn transistor at pin 9 of Arduino
const int airPump2 = 10;    //Air pump motor with npn transistor at pin 9 of Arduino
const int airPump3 = 11;    //Air pump motor with npn transistor at pin 9 of Arduino
const int airPump4 = 6;    //Air pump motor with npn transistor at pin 9 of Arduino

const int MPU=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
double pitch,roll;
int airPumpOutput = 0;




void setup(){
Serial.begin(9600);
pinMode(airPump1,OUTPUT);
pinMode(airPump2,OUTPUT);
pinMode(airPump3,OUTPUT);
pinMode(airPump4,OUTPUT);
airPumpOutput  = 255;
}



void loop(){


analogWrite(airPump1,0);
analogWrite(airPump2,255);
analogWrite(airPump3,255);
analogWrite(airPump4,255);
//Serial.print("airPumpOutput = ");Serial.println(airPumpOutput);
delay(1000); 

analogWrite(airPump1,255);
analogWrite(airPump2,0);
analogWrite(airPump3,255);
analogWrite(airPump4,255);
//Serial.print("airPumpOutput = ");Serial.println(airPumpOutput);
delay(1000);

analogWrite(airPump1,255);
analogWrite(airPump2,255);
analogWrite(airPump3,0);
analogWrite(airPump4,255);
//Serial.print("airPumpOutput = ");Serial.println(airPumpOutput);
delay(1000); 

analogWrite(airPump1,255);
analogWrite(airPump2,255);
analogWrite(airPump3,255);
analogWrite(airPump4,0);
//Serial.print("airPumpOutput = ");Serial.println(airPumpOutput);
delay(1000); 
}
