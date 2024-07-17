//TB6612FNG Hookup Guide
//https://learn.sparkfun.com/tutorials/tb6612fng-hookup-guide
// these constants are used to allow you to make your motor configuration
// line up with function names like forward.  Value can be 1 or -1

/*Now, for a quick overview of how to control each of the channels. If you are using an Arduino, don't worry about this too much as the library takes care of all of this for you. If you are using a different control platform, pay attention. When the outputs are set to High/Low your motor will run. When they are set to Low/High the motor will run in the opposite direction. In both cases, the speed is controlled by the PWM input.

In1	In2	PWM	Out1	Out2	Mode
H	H	H/L	L	L	Short brake
L	H	H	L	H	CCW
L	H	L	L	L	Short brake
H	L	H	H	L	CW
H	L	L	L	L	Short brake
L	L	H	OFF	OFF	Stop
*/

#define AIN1 8
#define AIN2 9
#define PWMA 10

#define PWMB 11
#define BIN1 12
#define BIN2 13

#define STBY 7
int motorSpd = 255;


void setup() {
    forward();
  delay(1000);
  stop();
  delay(1000);
  reverse();
  delay(1000);
  stop();
  delay(1000);
  spinL();
  delay(1000);
  stop();
  delay(1000);
  spinR();
  delay(1000);
  stop();
  delay(1000);
}

void loop() {

}

void forward() {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, motorSpd);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, motorSpd);
}

void reverse() {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, motorSpd);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, motorSpd);
}


void spinL() {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, motorSpd);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, motorSpd);
}

void spinR() {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, motorSpd);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, motorSpd);
}

void stop() {
  digitalWrite(STBY, LOW);
  digitalWrite(STBY, LOW);
}
