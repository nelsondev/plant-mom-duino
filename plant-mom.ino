long start_time = 0;
long stop_time = 0;

int seconds_to_ms(int seconds) {
    return seconds * 1000;
}

int minutes_to_ms(int minutes) {
    return seconds_to_ms(minutes * 60);
}

void setup() {
    Serial.begin(115200);

    start_time = 5000;
    stop_time  = 5000;

    pinMode(1, INPUT);
    pinMode(2, INPUT);
    pinMode(3, OUTPUT);

    digitalWrite(3, HIGH);
    digitalWrite(3, LOW);
}

void lights() {
    long offset_time = millis() - start_time;
    if (offset_time == stop_time) {
        start_time = millis();
    }
}

void inputs() {
    int button_1 = digitalRead(1);
    int button_2 = digitalRead(2);

    if (button_1 == 1 && button_2 == 1) {
        start_time = millis();
    }
    else if (button_1 == 1) {
        stop_time += 1000 * 60 * 15;
    }
    else if (button_2 == 1) {
        stop_time -= 1000 * 60 * 15;
    }
}

void loop() {
    lights();
    inputs();
}