
int ch1 = 2;
int ch2 = 3;
int ch3 = 4;
int ch4 = 5;
int d1 = 6;
int d2 = 9;
int d3 = 10;
int d4 = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);
  pinMode(ch3, INPUT);
  pinMode(ch4, INPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pwm1 = pulseIn(ch1, HIGH, 25000);
  int pwm2 = pulseIn(ch2, HIGH, 25000);
  int pwm3 = pulseIn(ch3, HIGH, 25000);
  int pwm4 = pulseIn(ch4, HIGH, 25000);

 
  int pitch = map(pwm2, 1000, 2000, -255, 255); //these are named after the axis names on the controller
  int roll = map(pwm3, 1000, 2000, -255, 255);
  int yaw = map(pwm4, 1000, 2000, -255, 255);

  if (pitch > 0) {
    if (roll > 0) {                       // add somwhere some abs(roll) to make it work to not do pitch - (-roll) because x - (-y) = x + y
      analogWrite(d1, (pitch - roll));
      analogWrite(d2, 0);
      analogWrite(d3, (pitch + roll));
      analogWrite(d4, 0);
    }
    else if (roll < 0) {
      analogWrite(d1, (pitch + abs(roll)));
      analogWrite(d2, 0);
      analogWrite(d3, (pitch - abs(roll)));
      analogWrite(d4, 0);
    }
    else {
      analogWrite(d1, pitch);
      analogWrite(d2, 0);
      analogWrite(d3, pitch);
      analogWrite(d4, 0);
    }
  }
  else if (pitch < 0) {
    if (roll > 0) {
      analogWrite(d1, 0)
      analogWrite(d2, (abs(pitch) + roll));
      analogWrite(d3, 0);
      analogWrite(d4, (abs(pitch) - roll));
    }
    else if (roll < 0) {
      analogWrite(d1, 0);
      analogWrite(d2, (abs(pitch) - abs(roll)));
      analogWrite(d3, 0);
      analogWrite(d4, (abs(pitch) + abs(roll)));
    }
    else {
      analogWrite(d1, 0);
      analogWrite(d2, (abs(pitch)));
      analogWrite(d3, 0);
      analogWrite(d4, (abs(pitch)));
    }
  }
  
  if (yaw > 0) {
    analogWrite(d1, 0);
    analogWrite(d2, yaw);
    analogWrite(d3, yaw);
    analogWrite(d4, 0);
  }
  else if (yaw < 0) {
    analogWrite(d1, yaw);
    analogwrite(d2, 0);
    analogWrite(d3, 0);
    analogWrite(d4, yaw);
  }
 
  
}
