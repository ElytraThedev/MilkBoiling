#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 7
#define DISTANCE_THRESHOLD 35  // Set distance threshold to 10 cm

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Send ultrasonic pulse
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Read echo time
    long duration = pulseIn(ECHO_PIN, HIGH);
    
    // Convert time to distance (in cm)
    float distance = duration * 0.0343 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // If object is within 10 cm, beep the buzzer
    if (distance > 0 && distance <= DISTANCE_THRESHOLD) {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(100);
        digitalWrite(BUZZER_PIN, LOW);
        delay(100);
    } else {
        digitalWrite(BUZZER_PIN, LOW);
    }

    delay(100);
}

