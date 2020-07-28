const int buzzerPin = 5;
const int rotaryPin = A0;

int rotaryValue = 0;
int buzzerValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
  pinMode(rotaryPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  rotaryValue = analogRead(rotaryPin);
  buzzerValue = map(rotaryValue, 0, 1023, 0, 255);
  analogWrite(buzzerPin, buzzerValue);

}
