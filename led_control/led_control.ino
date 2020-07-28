const int ledPin = 4;
const int buttonPin = 6;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // int buttonState = digitalRead(buttonPin);
  buttonState = digitalRead(buttonPin);

  digitalWrite(ledPin, buttonState);
  //if (buttonState == HIGH) {
  //  digitalWrite(ledPin, HIGH);
  //} else {
  //  digitalWrite(ledPin, LOW);
  //}
  
  // delay(500);
}
