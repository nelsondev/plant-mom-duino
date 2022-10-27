const int BUTTON_1_PIN = 1;
const int BUTTON_2_PIN = 2;
const int OUTPUT_1_PIN = 3;
const int OUTPUT_2_PIN = 4;

long start_time = 0;
long stop_time = 0;

int seconds_to_ms(int seconds) {
    return seconds * 1000;
}

int minutes_to_ms(int minutes) {
    return seconds_to_ms(minutes * 60);
}

void handle_lights() {
    long offset_time = millis() - start_time;
    if (offset_time == stop_time) {
        start_time = millis();
    }
}

void handle_inputs() {
    bool button_1 = digitalRead(BUTTON_1_PIN) == 1;
    bool button_2 = digitalRead(BUTTON_2_PIN) == 1;

    if (button_1 && button_2) {
        start_time = millis();
    }
    else if (button_1) {
        stop_time += 1000 * 60 * 15;
    }
    else if (button_2) {
        stop_time -= 1000 * 60 * 15;
    }
}

void setup() {
    Serial.begin(115200);

    start_time = seconds_to_ms(30);
    stop_time  = seconds_to_ms(30);

    pinMode(BUTTON_1_PIN, INPUT);
    pinMode(BUTTON_2_PIN, INPUT);
    pinMode(OUTPUT_1_PIN, OUTPUT);
    pinMode(OUTPUT_2_PIN, OUTPUT);
}

void loop() {
    handle_lights();
    handle_inputs();
}