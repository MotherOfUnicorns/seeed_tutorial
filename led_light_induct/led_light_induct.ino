const int sensorPin = A6;
const int ledPin = 4;
const int sensorThreshold = 10;
int sensorValue = 0;
int ledValue = 0;

void setup(){
    pinMode(sensorPin, INPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);

    if (sensorValue < sensorThreshold) {
        digitalWrite(ledPin, HIGH);
    }
    else {
        digitalWrite(ledPin, LOW);
    }

    delay(200);
}
