#include <Arduino.h>
#line 1 "/Users/nelr/Arduino/plant-mom/plant-mom.ino"
long start_time = 0;
long stop_time = 0;

#line 4 "/Users/nelr/Arduino/plant-mom/plant-mom.ino"
void setup();
#line 11 "/Users/nelr/Arduino/plant-mom/plant-mom.ino"
void loop();
#line 4 "/Users/nelr/Arduino/plant-mom/plant-mom.ino"
void setup() {
    Serial.begin(115200);

    start_time = 5000;
    stop_time  = 5000;
}

void loop() {
    long a = millis() - start_time;
    if (a == stop_time) {
        Serial.println("Yes");
        start_time = millis();
    }
}
