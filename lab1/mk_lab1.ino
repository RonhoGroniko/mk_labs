const int buttonPin = 7;   // Пин кнопки
const int ledPin1 = 8;     // Первый светодиод
const int ledPin2 = 9;     // Второй светодиод

bool isBlinking = false;   // Статус мигания
bool lastButtonState = LOW;
unsigned long previousMillis = 0;
const long interval = 500; // Интервал мигания (500 мс)

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Настраиваем кнопку с подтягивающим резистором
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin);

  // Обработка нажатия кнопки (переходное состояние)
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    isBlinking = !isBlinking; // Переключение состояния
    delay(50);               
  }
  lastButtonState = currentButtonState;

  // Логика мигания
  if (isBlinking) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      // Переключаем состояние светодиодов попеременно
      if (digitalRead(ledPin1) == LOW) {
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, LOW);
      } else {
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, HIGH);
      }
    }
  } else {
    // Если мигание выключено, гасим оба светодиода
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
}
