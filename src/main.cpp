#include <Arduino.h>
#include <Servo.h>

struct pair {
  float x, y;
};

const int ff = 64;
pair circle[ff];


Servo ml, mr;

float pi = 3.1415928;
float l = 7; // Length of link in cm
float d = 4; // Distance between origins in cm
float x, y, dl, dr, hl, hr;
float pl1, pl2, pr1, pr2;
int tl, tr;

float angle_left(float x, float y) {
  //Serial.println("Left: ");
  
  dl = sqrt((x * x) + (y * y)); // Distance between origin left and (x,y) point
  hl = sqrt((l * l) - ((dl / 2) * (dl / 2))); // Height of the triangle
  
  pl1 = atan2(hl, dl / 2); // Phi 1, angle between d and axis
  pl2 = atan2(y, x); // Phi 2, angle between d and l 
  
  tl = (pl1 + pl2) * 180 / pi; // Angle between axis and l

/*   Serial.println(hl);
  Serial.println(pl1 * 180 / pi);
  Serial.println(pl2 * 180 / pi);
  Serial.println(tl); */

  return tl;
}

float angle_right(float x, float y) {
  x -= d;

  //Serial.println("Right: ");
  
  dr = sqrt((x * x) + (y * y)); // Distance between origin right and (x,y) point
  hr = sqrt((l * l) - ((dr / 2) * (dr / 2))); // Height of the triangle

  pr1 = atan2(hr, dr / 2); // Phi 1, angle between d and axis
  pr2 = atan2(y, x); // Phi 2, angle between d and l 

  tr = (pr2 - pr1) * 180 / pi;

  /* Serial.println(hr);
  Serial.println(pr1 * 180 / pi);
  Serial.println(pr2 * 180 / pi);
  Serial.println(tr); */

  return tr;
}

// Extreme Left Point
void xleft() { 
  mr.write(110);
  ml.write(110);
}

// Extreme Right Point
void xright() { 
  mr.write(45);
  ml.write(45);
}

// Extreme Top Point
void xtop() {
  mr.write(90);
  ml.write(90);
}

// Extreme Bottom Point 
void xbottom() {
  mr.write(60);
  ml.write(120);
}

void vertical_straight_line() {
  x = 2; // Adjusted starting x position for the new distance between origins
  y = 6;

  for (y = 6; y < 12; y += 0.5) { 
    ml.write(angle_left(x, y));
    mr.write(angle_right(x, y));
    delay(50);
  }

  for (y = 11; y > 5; y -= 0.5) { 
    ml.write(angle_left(x, y));
    mr.write(angle_right(x, y));
    delay(50);
  }
}

void horizontal_straight_line() {
  x = 0;
  y = 6;

  for (x = 0; x < 7; x += 1) {
    ml.write(angle_left(x, y));
    mr.write(angle_right(x, y));
    delay(500);
  }
}

void compute_circle(pair pos, pair points[], int circle_radius) {
  const float angle = radians(360.0 / ff);

  for (int i = 0; i < ff; i++)
    points[i] = {pos.x + sin(angle * i) * circle_radius, pos.y + cos(angle * i) * circle_radius};
}

void setup() {
  ml.attach(5);
  mr.attach(3);
  Serial.begin(115200);
  ml.write(90);
  mr.write(90);
  delay(2000);

  compute_circle({0, 9}, circle, 1);
}

void loop() {
  for (int i = 0; i < ff; i++) {
    //Serial.println("Circle: ");
    Serial.println(circle[i].x);
    Serial.println(circle[i].y);
    ml.write(angle_left(circle[i].x, circle[i].y));
    mr.write(angle_right(circle[i].x, circle[i].y));
    delay(10);
  }

  //for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
  //  x = a[i][0];
  //  y = a[i][1] + 5;

  //  ml.write(angle_left(x, y));
  //  mr.write(angle_right(x, y));
  //  delay(300);  
  //}

  // for (int i = 0; i < 180; i += 10) {
  //   ml.write(i);
  //   delay(100);
  // }
  // for (int i = 180; i >= 0; i -= 10) {
  //   ml.write(i);
  //   delay(100);
  // }

  // x = -5;
  // y = 6;
  // ml.write(angle_left(x, y));
  // mr.write(angle_right(x, y));
  // delay(1000);
}