#include <Arduino.h>
#include <Servo.h>

Servo servoLeft, servoRight;
const float pi = 3.14159;
const float l = 6.9;
const float d = 4;

float x, y, dl, dr, hl, hr;
float pl1, pl2, pr1, pr2;
int tl, tr;

float angleLeft(float x, float y) {
  Serial.println("Left: ");

  dl = sqrt(x * x + y * y);
  hl = sqrt(l * l - (dl / 2) * (dl / 2));
  pl1 = atan2(hl, dl / 2);
  pl2 = atan2(y, x);
  
  tl = (pl1 + pl2) * 180 / pi;

  Serial.println(hl);
  Serial.println(pl1 * 180 / pi);
  Serial.println(pl2 * 180 / pi);

  Serial.println(tl);
  return tl;
}

float angleRight(float x, float y) {
  x -= d;

  Serial.println("Right : ");
  
  dr= sqrt(x * x + y * y);
  hr=sqrt(l * l - (dr / 2) * (dr / 2));
  pr1=atan2(hr, dr / 2);
  pr2= atan2(y, x);

  tr = (pr2 - pr1) * 180 / pi;


  Serial.println(hr);
  Serial.println(pr1 * 180 / pi);
  Serial.println(pr2 * 180 / pi);

  Serial.println(tr);
  return tr;
}

void xLeft() {
  mr.write(90);
}

void setup() {

}

void loop() {

}