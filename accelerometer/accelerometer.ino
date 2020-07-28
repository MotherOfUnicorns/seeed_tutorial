//Gravity Acceleration
#include "LIS3DHTR.h"
#ifdef SOFTWAREWIRE
    #include <SoftwareWire.h>
    SoftwareWire myWire(3, 2);
    LIS3DHTR<SoftwareWire> LIS;       //Software I2C
    #define WIRE myWire
#else
    #include <Wire.h>
    LIS3DHTR<TwoWire> LIS;           //Hardware I2C
    #define WIRE Wire
#endif


const int ledPin = 4;
const int interval = 1000;
float xAcc, yAcc, zAcc;
float xAccNew, yAccNew, zAccNew;

void setup() {
    Serial.begin(9600);
    // while (!Serial) {}; // only run when serial monitor is open

    LIS.begin(WIRE, 0x19); //IIC init
    delay(100);
    LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);

    pinMode(ledPin, OUTPUT);
}

void loop() {
    if (!LIS) {
        Serial.println("LIS3DHTR didn't connect.");
        while (1);
        return;
    }
    //3 axis
    xAcc = LIS.getAccelerationX();
    yAcc = LIS.getAccelerationY();
    zAcc = LIS.getAccelerationZ();
    // Serial.print("x:"); Serial.print(LIS.getAccelerationX()); Serial.print("  ");
    // Serial.print("y:"); Serial.print(LIS.getAccelerationY()); Serial.print("  ");
    // Serial.print("z:"); Serial.println(LIS.getAccelerationZ());
    Serial.print(xAcc);
    Serial.print(", ");
    Serial.print(yAcc);
    Serial.print(", ");
    Serial.println(zAcc);
    delay(interval / 2);

    xAccNew = LIS.getAccelerationX();
    yAccNew = LIS.getAccelerationY();
    zAccNew = LIS.getAccelerationZ();
    Serial.print(xAccNew);
    Serial.print(", ");
    Serial.print(yAccNew);
    Serial.print(", ");
    Serial.println(zAccNew);
    if (abs(xAccNew - xAcc) > 0.5) {
        digitalWrite(ledPin, HIGH);
        delay(50);
        digitalWrite(ledPin, LOW);
        delay(200);
    } else if (abs(yAccNew - yAcc) > 0.5) {
        digitalWrite(ledPin, HIGH);
        delay(50);
        digitalWrite(ledPin, LOW);
        delay(50);
        digitalWrite(ledPin, HIGH);
        delay(150);
        digitalWrite(ledPin, LOW);
    } else if (abs(zAccNew - zAcc) > 0.5) {
        digitalWrite(ledPin, HIGH);
        delay(50);
        digitalWrite(ledPin, LOW);
        delay(50);
        digitalWrite(ledPin, HIGH);
        delay(50);
        digitalWrite(ledPin, LOW);
        delay(50);
        digitalWrite(ledPin, HIGH);
        delay(50);
        digitalWrite(ledPin, LOW);
    }
    delay(interval / 2 - 250);
}
