#include <math.h>

#include <Servo.h>
int top = 10;
int delayT = 60;
int frameCount = 0;

const int airPump = 9;    //Air pump motor with npn transistor at pin 9 of Arduino

const int MPU=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
double pitch,roll;
int airPumpOutput = 0;




void setup(){
Serial.begin(9600);
pinMode(airPump,OUTPUT);

}



void loop(){

airPumpOutput  = 255;
analogWrite(airPump,airPumpOutput);
//Serial.print("airPumpOutput = ");Serial.println(airPumpOutput);
delay(1000); 

airPumpOutput = 0;
analogWrite(airPump,airPumpOutput);
//Serial.print("airPumpOutput = ");Serial.println(airPumpOutput);
delay(1000); 
}
