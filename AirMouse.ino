const int vcc = A1;
const int xPin = A2;
const int yPin = A3;
const int zPin = A4;
const int gnd = A5;
const int btn1 = 11;
const int btn2 = 12;
const int VRx = A6;
const int VRy = A7;
const int SW = 2;

int xRaw, yRaw, zRaw;
int x, y, z;
int xPosition = 0, yPosition = 0;
int mapX = 0, mapY = 0;
int state1, state2;
int SW_state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(vcc, OUTPUT);
  pinMode(gnd, OUTPUT);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(SW, INPUT);
  digitalWrite(btn1, HIGH);
  digitalWrite(btn2, HIGH);
  digitalWrite(SW, HIGH);
  digitalWrite(vcc, HIGH);
  digitalWrite(gnd, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  xRaw = analogRead(xPin);
  yRaw = analogRead(yPin);
  zRaw = analogRead(zPin);
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  state1 = digitalRead(btn1);
  state2 = digitalRead(btn2);
  SW_state = digitalRead(SW);
  x = map(xRaw, 269, 400, -100, 100);
  y = map(yRaw, 272, 400, -100, 100);
  z = map(zRaw, 272, 400, -100, 100);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(z);
  Serial.print(" ");
  Serial.print(state1);
  Serial.print(" ");
  Serial.print(state2);
  Serial.print(" ");
  Serial.print(mapX);
  Serial.print(" ");
  Serial.print(mapY);
  Serial.print(" ");
  Serial.println(SW_state);
}
