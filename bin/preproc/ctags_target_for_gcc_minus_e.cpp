# 1 "/Users/nelr/Arduino/plant-mom/plant-mom.ino"
long start_time = 0;
long stop_time = 0;

void setup() {
    Serial.begin(115200);

    start_time = 5000;
    stop_time = 5000;
}

void loop() {
    long a = millis() - start_time;
    if (a == stop_time) {
        Serial.println("Yes");
        start_time = millis();
    }
}
