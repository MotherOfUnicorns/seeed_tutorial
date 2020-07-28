//Air pressure detection, also detects temperature
#include "Seeed_BMP280.h"
#include <Wire.h>
#include <U8x8lib.h>

 
BMP280 bmp280;
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);


float pressure, temperature, altitude;

void setup() {
    Serial.begin(9600);
    if (!bmp280.init()) {
        Serial.println("Device not connected or broken!");
    }
    u8x8.begin();
    u8x8.setPowerSave(0);  
    u8x8.setFlipMode(0);
}

void loop() {
    //get and print temperatures
    temperature = bmp280.getTemperature();
    pressure = bmp280.getPressure();
    altitude = bmp280.calcAltitude(pressure);

    u8x8.setFont(u8x8_font_chroma48medium8_r);
    u8x8.setCursor(0, 0);
    u8x8.print("Temp:");
    u8x8.print(temperature);
    u8x8.print("C");
    u8x8.setCursor(0, 1);
    u8x8.print("Press:");
    u8x8.print(pressure / 1000);
    u8x8.print("kPa");
    u8x8.setCursor(0, 2);
    u8x8.println("Est. altitude:");
    u8x8.print(altitude);
    u8x8.print("m");

    delay(1000);
}
