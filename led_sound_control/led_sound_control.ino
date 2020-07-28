const int ledPin = 4;
const int sensorPin = A2;

int sensorValue = 0;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(sensorPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);

    if (sensorValue > 400) {
        digitalWrite(ledPin, HIGH);
        delay(100);
    }
    else {
        digitalWrite(ledPin, LOW);
    }
}
