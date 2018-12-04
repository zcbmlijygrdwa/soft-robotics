#include<Wire.h>
#include <math.h>

#include <Servo.h>
int top = 10;
int delayT = 60;
int frameCount = 0;

const int airPump2 = 9;    //Air pump motor with npn transistor at pin 9 of Arduino
const int airPump3 = 10;    //Air pump motor with npn transistor at pin 9 of Arduino
const int airPump4 = 11;    //Air pump motor with npn transistor at pin 9 of Arduino
const int airPump1 = 6;    //Air pump motor with npn transistor at pin 9 of Arduino



const int MPU = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
double pitch, roll;
double angleThres = 0.5;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);

  pinMode(airPump1, OUTPUT);
  pinMode(airPump2, OUTPUT);
  pinMode(airPump3, OUTPUT);
  pinMode(airPump4, OUTPUT);
}


int calSeconds(int degree)
{
  int minSec = 640;
  int maxSec = 740;

  return minSec + (maxSec - minSec) * (degree * 1.0 / 180);


}


void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true);

  int AcXoff, AcYoff, AcZoff, GyXoff, GyYoff, GyZoff;
  int temp, toff;
  double t, tx, tf;

  //Acceleration data correction
  AcXoff = -950;
  AcYoff = -300;
  AcZoff = 0;

  //Temperature correction
  toff = -1600;

  //Gyro correction
  GyXoff = 480;
  GyYoff = 170;
  GyZoff = 210;

  //read accel data
  AcX = (Wire.read() << 8 | Wire.read()) + AcXoff;
  AcY = (Wire.read() << 8 | Wire.read()) + AcYoff;
  AcZ = (Wire.read() << 8 | Wire.read()) + AcYoff;

  //read temperature data
  temp = (Wire.read() << 8 | Wire.read()) + toff;
  tx = temp;
  t = tx / 340 + 36.53;
  tf = (t * 9 / 5) + 32;

  //read gyro data
  GyX = (Wire.read() << 8 | Wire.read()) + GyXoff;
  GyY = (Wire.read() << 8 | Wire.read()) + GyYoff;
  GyZ = (Wire.read() << 8 | Wire.read()) + GyZoff;

  //get pitch/roll
  getAngle(AcX, AcY, AcZ);

  //send the data out the serial port
  Serial.print("Angle: ");
  Serial.print("Pitch = ");
  Serial.println(pitch);


  Serial.print(" | Roll = "); Serial.println(roll);
  //analogWrite(airPump,255);

  if (abs(roll) > angleThres)
  {
    if (roll < 0) {
      analogWrite(airPump1, 0);
      analogWrite(airPump4, 255);
    }
    else
    {
      analogWrite(airPump1, 255);
      analogWrite(airPump4, 0);
    }
  }
    else
  {
    analogWrite(airPump1, 255);
    analogWrite(airPump4, 255);
  }

  if (abs(pitch) > angleThres)
  {
    if (pitch < 0) {
      analogWrite(airPump2, 255);
      analogWrite(airPump3, 0);
    }
    else
    {
      analogWrite(airPump2, 0);
      analogWrite(airPump3, 255);
    }
  }
  else
  {
    analogWrite(airPump2, 255);
    analogWrite(airPump3, 255);
  }

  Serial.print("Temp: ");
  Serial.print("Temp(F) = "); Serial.print(tf);
  Serial.print(" | Temp(C) = "); Serial.println(t);

  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ);

  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX);
  Serial.print(" | Y = "); Serial.print(GyY);
  Serial.print(" | Z = "); Serial.println(GyZ);
  Serial.println(" ");
  delay(5);
}

//convert the accel data to pitch/roll
void getAngle(int Vx, int Vy, int Vz) {
  double x = Vx;
  double y = Vy;
  double z = Vz;

  pitch = atan(x / sqrt((y * y) + (z * z)));
  roll = atan(y / sqrt((x * x) + (z * z)));
  //convert radians into degrees
  pitch = pitch * (180.0 / 3.14);
  roll = roll * (180.0 / 3.14) ;





}
