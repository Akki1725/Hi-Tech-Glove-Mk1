const int vcc = A1;
const int xPin = A2;
const int yPin = A3;
const int zPin = A4;
const int gnd = A5;
const int SW = 2;
const int vrt = 13;
const int vrx = A7;
const int vry = 11;

int xRaw, yRaw, zRaw;
int x, y, z;
int xPosition = 0, yPosition = 0;
int mapX = 0, mapY = 0;
int state1, state2;
int SW_state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(vcc, OUTPUT);
  pinMode(gnd, OUTPUT);
  pinMode(vrt, OUTPUT);
  pinMode(SW, INPUT);
  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);
  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);
  digitalWrite(SW, HIGH);
  digitalWrite(vcc, HIGH);
  digitalWrite(gnd, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  xRaw = analogRead(xPin);
  yRaw = analogRead(yPin);
  zRaw = analogRead(zPin);
  SW_state = digitalRead(SW);
  xPosition = analogRead(vrx);
  yPosition = analogRead(vry);
  x = map(xRaw, 269, 400, -100, 100);
  y = map(yRaw, 272, 400, -100, 100);
  z = map(zRaw, 272, 400, -100, 100);
  mapX = map(xPosition, 0, 1023, 0, 255);
  mapY = map(yPosition, 0, 1023, 0, 255);
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(z);
  Serial.print(" ");
  Serial.print(xPosition);
  Serial.print(" ");
  Serial.print(mapY);
  Serial.print(" ");
  Serial.println(SW_state);
}
