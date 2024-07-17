/*
  LilyBot-LilyButtonMotion.ino
  This code will use a red, green, and yellow button to 
  drive the robot forward, reverse, and spin while turning on
  red, yellow, and green buttons.
*/

/* Hardware Connections */
//the right motor will be controlled by the motor A pins on the motor driver
const int AIN1 = 13;  //control pin 1 on the motor driver for the right motor
const int AIN2 = 12;  //control pin 2 on the motor driver for the right motor
const int PWMA = 11;  //speed control pin on the motor driver for the right motor

//the left motor will be controlled by the motor B pins on the motor driver
const int PWMB = 10;  //speed control pin on the motor driver for the left motor
const int BIN2 = 9;   //control pin 2 on the motor driver for the left motor
const int BIN1 = 8;   //control pin 1 on the motor driver for the left motor
const int grnbtn = 7;
const int ylwbtn = 6;
const int redbtn = 5;
const int grnLed = 4;
const int ylwLed = 3;
const int redLed = 2;

const int waittime = 1000;  //movement delay

float distance = 0;  //variable to store the distance measured by the distance sensor

//robot behavior variables
int backupTime = 300;  //amount of time that the robot will back up when it senses an object
int turnTime = 200;    //amount that the robot will turn once it has backed up
int oneSecond = 1000;  //one second variable
int robotSpeed = 150;

/********************************************************************************/
void setup() {
  //this function only runs once

  pinMode(grnbtn, INPUT_PULLUP);  //set this as a pullup to sense whether the switch is flipped
  pinMode(ylwbtn, INPUT_PULLUP);  //set this as a pullup to sense whether the switch is flipped
  pinMode(redbtn, INPUT_PULLUP);  //set this as a pullup to sense whether the switch is flipped

  pinMode(redLed, OUTPUT);
  pinMode(grnLed, OUTPUT);
  pinMode(ylwLed, OUTPUT);

  //set the motor control pins as outputs
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  forward();
  ALL_LEDS_ON();
  delay(1000);
  ALL_LEDS_OFF();
  stop();


  Serial.begin(9600);                       //begin serial communication with the computer
  Serial.print("To infinity and beyond!");  //test the serial connection
}


/********************************************************************************/
void loop() {
  if (digitalRead(grnbtn) == LOW) {
    forward();
    digitalWrite(grnLed, HIGH);
    delay(waittime);
    stop();
  }
  if (digitalRead(ylwbtn) == LOW) {
    spin(1);
    digitalWrite(ylwLed, HIGH);
    delay(waittime);
    stop();
  }
  if (digitalRead(redbtn) == LOW) {
    reverse();
    digitalWrite(redLed, HIGH);
    delay(waittime);
    stop();
  }
  LedsOff();
}

void LedsOff() {
  digitalWrite(redLed, LOW);
  digitalWrite(ylwLed, LOW);
  digitalWrite(grnLed, LOW);
}

//robot stop function
void stop() {
  //left motor stop
  digitalWrite(AIN1, LOW);  //set pin 1 to low
  digitalWrite(AIN2, LOW);  //set pin 2 to low
  //right motor stop
  digitalWrite(BIN1, LOW);  //set pin 1 to low
  digitalWrite(BIN2, LOW);  //set pin 2 to low
}

//robot forward function
void forward() {
  //left motor CCW
  digitalWrite(AIN1, HIGH);  //set pin 1 to high
  digitalWrite(AIN2, LOW);   //set pin 2 to low
  //right motor CW
  digitalWrite(BIN1, HIGH);  //set pin 1 to low
  digitalWrite(BIN2, LOW);   //set pin 2 to high
  //set motor speeds
  analogWrite(PWMA, abs(robotSpeed));  //set forward speed
  analogWrite(PWMB, abs(robotSpeed));  //set forward speed
}

//robot reverse function
void reverse() {
  //left motor CW
  digitalWrite(AIN1, LOW);   //set pin 1 to low
  digitalWrite(AIN2, HIGH);  //set pin 2 to high
  //right motor CCW
  digitalWrite(BIN1, LOW);   //set pin 1 to low
  digitalWrite(BIN2, HIGH);  //set pin 2 to high
  //set motor speeds
  analogWrite(PWMA, abs(robotSpeed));  //set reverse speed
  analogWrite(PWMB, abs(robotSpeed));  //set reverse speed
}

//robot spin function in specified direction 1 CW, 0 CCW
void spin(int dir) {
  if (dir) {
    //left motor CW
    digitalWrite(AIN1, HIGH);  //set pin 1 to low
    digitalWrite(AIN2, LOW);   //set pin 2 to high
    //right motor CW
    digitalWrite(BIN1, LOW);   //set pin 1 to low
    digitalWrite(BIN2, HIGH);  //set pin 2 to high
  } else {
    //left motor CCW
    digitalWrite(AIN1, LOW);   //set pin 1 to low
    digitalWrite(AIN2, HIGH);  //set pin 2 to high
    //right motor CCW
    digitalWrite(BIN1, HIGH);  //set pin 1 to low
    digitalWrite(BIN2, LOW);   //set pin 2 to high
  }
  //set motor speeds
  analogWrite(PWMA, abs(robotSpeed));  //set left speed
  analogWrite(PWMB, abs(robotSpeed));  //set right speed
}
// turn LEDS off function
void ALL_LEDS_OFF() {
  digitalWrite(grnLed, LOW);
  digitalWrite(ylwLed, LOW);
  digitalWrite(redLed, LOW);
}

// all LEDS ON
void ALL_LEDS_ON() {
  digitalWrite(grnLed, HIGH);
  digitalWrite(ylwLed, HIGH);
  digitalWrite(redLed, HIGH);
}
