
// #include <Arduino.h>

// const int ledPin = 23;
// const int channel = 0;
// const int freq = 5000;
// const int resolution = 8;

// void setup() {
//   ledcSetup(channel, freq, resolution);
//   ledcAttachPin(ledPin, channel);
// }

// void loop() {
//   for (int duty = 0; duty <= 255; duty++) {
//     ledcWrite(channel, duty);
//     delay(10);
//   }

//   for (int duty = 255; duty >= 0; duty--) {
//     ledcWrite(channel, duty);
//     delay(10);
//   }
// }



#include <Arduino.h>

constexpr uint8_t LED_PIN = 2;
constexpr uint32_t PWM_FREQUENCY = 5000;
constexpr uint8_t PWM_RESOLUTION = 8;
constexpr uint16_t PWM_MAX_DUTY = 255;

void setup()
{
    Serial.begin(115200);

    ledcSetup(0, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(LED_PIN, 0);

    ledcWrite(0, 0);

    Serial.println("ESP32 PWM LED Fade Started");
}

void loop()
{
    for (int duty = 0; duty <= PWM_MAX_DUTY; duty++)
    {
        ledcWrite(0, duty);
        delay(10);
    }

    for (int duty = PWM_MAX_DUTY; duty >= 0; duty--)
    {
        ledcWrite(0, duty);
        delay(10);
    }
}
