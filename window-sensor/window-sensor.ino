#define SENSOR_PIN      2

#define BUTTON_ON_PIN   4
#define BUTTON_OFF_PIN  5

#define RED_DIODE_PIN   7
#define GREEN_DIODE_PIN 8
#define BLUE_DIODE_PIN  9

#define BUZZER_PIN      11

bool isAlarmOn = false;

void setup() {
  pinMode(SENSOR_PIN, INPUT_PULLUP);

  pinMode(BUTTON_ON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_OFF_PIN, INPUT_PULLUP);

  pinMode(RED_DIODE_PIN, OUTPUT);
  pinMode(GREEN_DIODE_PIN, OUTPUT);
  pinMode(BLUE_DIODE_PIN, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  bool isWindowOpened = digitalRead(SENSOR_PIN) == HIGH;
  bool isOnButtonPressed = digitalRead(BUTTON_ON_PIN) == LOW;
  bool isOffButtonPressed = digitalRead(BUTTON_OFF_PIN) == LOW;

  if (isOffButtonPressed) {
    isAlarmOn = false;
  }

  if (isOnButtonPressed) {
    isAlarmOn = true;
  }

  digitalWrite(BLUE_DIODE_PIN, isAlarmOn);

  if (!isWindowOpened) {
    digitalWrite(RED_DIODE_PIN, LOW);
    digitalWrite(GREEN_DIODE_PIN, HIGH);
    return; 
  }

  if (!isAlarmOn) {
    digitalWrite(RED_DIODE_PIN, HIGH);
    digitalWrite(GREEN_DIODE_PIN, LOW);
    return;
  }

  digitalWrite(GREEN_DIODE_PIN, LOW);
  digitalWrite(RED_DIODE_PIN, HIGH);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(RED_DIODE_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  delay(500);
}
