#define SENSOR_PIN     2

#define BUTTON_ON_PIN  4
#define BUTTON_OFF_PIN 5

#define RED_LED_PIN    7
#define GREEN_LED_PIN  8
#define BLUE_LED_PIN   9

#define BUZZER_PIN     11

bool isAlarmOn = false;

void setup() {
  pinMode(SENSOR_PIN, INPUT_PULLUP);

  pinMode(BUTTON_ON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_OFF_PIN, INPUT_PULLUP);

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);

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

  digitalWrite(BLUE_LED_PIN, isAlarmOn);

  if (!isWindowOpened) {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    return; 
  }

  if (!isAlarmOn) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    return;
  }

  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  delay(500);
}
