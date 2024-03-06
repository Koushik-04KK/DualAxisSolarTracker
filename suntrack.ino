

#include <VarSpeedServo.h>


VarSpeedServo myservo1, myservo2;
int LDR1 = A0, LDR2 = A1, LDR3 = A2, LDR4 = A3;
int rRDL1 = 0, rRDL2 = 0, rRDL3 = 0, rRDL4 = 0;
int max1=0, max2=0, max3=0;

void setup() {
  myservo1.attach(9);
  myservo2.attach(8);

  Serial.begin(9600);
  myservo1.write(90);
  myservo2.write(90);
}

void loop() {

  rRDL1 = analogRead(LDR1) / 100;
  rRDL2 = analogRead(LDR2) / 100;
  rRDL3 = analogRead(LDR3) / 100;
  rRDL4 = analogRead(LDR4) / 100;

  if((rRDL1 && rRDL4) == HIGH  && (rRDL2 && rRDL3)==LOW) {
    myservo1.slowmove(120,100);
    myservo2.slowmove(180,100);
  }
  else if((rRDL1 && rRDL3) ==  HIGH && (rRDL2 && rRDL4) == LOW) {
    myservo1.write(120);
    myservo2.write(90);
  }
  else if( (rRDL2 && rRDL3) == HIGH && (rRDL1 && rRDL4) == LOW) {
    myservo1.write(120);
    myservo2.write(0);
  }
  else if( (rRDL4 && rRDL2) == HIGH && (rRDL1 && rRDL3) == LOW) {
    myservo1.write(60);
    myservo2.write(90);
  }
  else if((rRDL1 && rRDL2) == LOW && (rRDL3 && rRDL4) == LOW) {
    myservo1.write(90);
    myservo2.write(90);
  }
  delay(100);
}
