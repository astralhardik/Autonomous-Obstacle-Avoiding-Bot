/*
 * ----------------------------------------------------------------------------
 * Project Title   : Autonomous Obstacle Avoiding Robot
 * Description     : This project is part of the Design Lab coursework where 
 *                   an autonomous bot was designed using ultrasonic sensors 
 *                   and servo-based scanning to avoid obstacles. It uses an 
 *                   LCD for status display, and dual motor control for movement 
 *                   decisions based on environmental sensing.
 *
 * Author          : Hardik Agrawal
 * Institution     : The LNM Institute of Information Technology (LNMIIT)
 * Course          : Design Lab Project
 * ----------------------------------------------------------------------------
 */

#include <Servo.h>          
#include <NewPing.h>        
#include<LiquidCrystal_I2C.h>
#include<Wire.h>

 #define LeftMotorForward  11
 #define LeftMotorBackward 6
 #define RightMotorForward 10
 #define  RightMotorBackward 9

//sensor pins
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //our servo name

LiquidCrystal_I2C lcd(0x3f,16,2);

void setup(){

  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  servo_motor.attach(5); //our servo pin

  servo_motor.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  Serial.println(distance);
}


int lookRight(){  
  servo_motor.write(60);
  delay(100);
  int distance = readPing();
  delay(700);
  servo_motor.write(115);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(100);
  int distance = readPing();
  delay(700);
  servo_motor.write(115);
  return distance;
}

int readPing(){
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  Serial.println("Stop");
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Stop");
  delay(500);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    // digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorForward,220);
    //analogWrite(RightMotorForward,220);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
    Serial.println("Going Forward");
    
    lcd.setCursor(0,0);
    lcd.print("Going Forward");
    delay(700);
  }
}

void moveBackward(){

  goesForward=false;
  // digitalWrite(LeftMotorBackward, HIGH);
  // digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(RightMotorBackward,220);
  digitalWrite(LeftMotorBackward,220);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  Serial.println("Going Backward");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Going Backward");
  delay(700);
  
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  Serial.println("Turning Right");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Going Right");
  
  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);

}

void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  Serial.println("Turning Left");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Going Left");

  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 25){
    moveStop();
    delay(200);
    moveBackward();
    delay(400);
    moveStop();
    delay(200);
    
    distanceRight = lookRight();
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Right Distance:");
    Serial.println("Right Distance:");
    lcd.setCursor(0,1);
    lcd.print(distanceRight);
    Serial.print(distanceRight);
    delay(300);
    
    distanceLeft = lookLeft();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Left Distance:");
    Serial.println("left distance:");
    lcd.setCursor(0,1);
    lcd.print(distanceLeft);
    Serial.print(distanceLeft);
    delay(300);

    if (distanceLeft > distanceRight){
      turnLeft();
      moveStop();
    }
    else{
      turnRight();
      moveStop();
    }
  }
  else{

    moveForward(); 
  }
    distance = readPing();
}