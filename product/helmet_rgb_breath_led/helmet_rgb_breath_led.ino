// From: https://github.com/cano64/ArduinoSystemStatus
#include <SystemStatus.h>

// For W2812B
#include <Adafruit_NeoPixel.h>

#define VOLTAGE_THRESHOLD  2.8 //低於 2.8V 就改亮紅色

#define LED_PIN         PB1
#define ALL_NUM_LEDS        16
#define NUM_LEDS        16


Adafruit_NeoPixel strip = Adafruit_NeoPixel(ALL_NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
    strip.begin();
    strip.show();  // 將所有 LED 關閉       
}

static unsigned long lastVoltageCheck = 0; 
static bool lowVoltage = false; //低電壓嗎
static int maxBlueBrightness = 40; //藍光時 40
static int maxRedBrightness = 60; //紅光時 60
static int maxBrightness = maxBlueBrightness; 

static int delayBlueSpeed = 100; // 藍光時 100
static int delayRedSpeed = 60; // 紅光時 60
static int delaySpeed = delayBlueSpeed; 

void loop() {
    // 每 3 秒檢測一次電壓   
    if (millis() - lastVoltageCheck > 3000) {
        lastVoltageCheck = millis();
        float batteryVoltage = SystemStatus().getVCC()/1000.0;        
        if (batteryVoltage < VOLTAGE_THRESHOLD) {
            lowVoltage = true;
        } else {
            lowVoltage = false;
        }
    }

    // 如果低電壓，顯示紅色呼吸燈效果；否則正常呼吸燈效果
    if (lowVoltage) {
        breathingEffect("RED");
    } else {
        breathingEffect("BLUE");
    }
}

// 呼吸燈效果函數
void breathingEffect(const String &color) {
    static uint8_t brightness = 1;
    static int8_t delta = 1;

    brightness = brightness + delta;
    if (brightness == 1 || brightness == maxBrightness) {
        delta = -delta;
    }
    for (int i = 0; i < NUM_LEDS; i++) {       
        if (color == "RED") {
            strip.setPixelColor(i, strip.Color(255, 0, 0));
            maxBrightness = maxRedBrightness;
            delaySpeed = delayBlueSpeed;
        } else if (color == "BLUE") {
            strip.setPixelColor(i, strip.Color(0, 0, 255));
            maxBrightness = maxBlueBrightness;
            delaySpeed = delayRedSpeed;
        }        
    }
    strip.setBrightness(brightness);  // 設置亮度
    strip.show();
    delay(delaySpeed);  // 調整呼吸燈效果的速度
}
