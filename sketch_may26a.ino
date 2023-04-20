int trig = 5;
int echo = 6;
long duration;
long distance;
int force;

void setup() {
 pinMode(echo, INPUT);
 pinMode(trig, OUTPUT);
 Serial.begin(9600);
}
void loop() {
 digitalWrite(trig, LOW);
 delayMicroseconds(2);
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);
 duration = pulseIn(echo, HIGH);
 distance = (duration / 2) * .0344;
//int note [14] ={261,293,329,349, 392,440, 493, 523, 587, 659, 698, 783, 880, 987 }; // notes from C4 to B5
int note[7] = {262, 294, 330, 349, 392, 440, 494}; // C4 D4 E4 F4 G4 A4 B4
 force = analogRead(A0);
 if (distance < 0 || distance > 30 || force < 100) {
 noTone(12);
 }
 else if ((force > 100)) {
 int sound = map(distance, 0, 30, 0, 6);
 tone(12, note[sound]);
 }
}
