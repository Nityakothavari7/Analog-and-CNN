#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define EMG_PIN A0
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SERVO_PIN 9

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Servo therapyServo;

String inputString = "";
bool newData = false;

void setup() {
  Serial.begin(115200);
  therapyServo.attach(SERVO_PIN);
  therapyServo.write(90);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.println("Waiting for data...");
  display.display();
}

void loop() {
  static unsigned long prevEMGTime = 0;
  if (millis() - prevEMGTime >= 10) {
    prevEMGTime = millis();
    int emgValue = analogRead(EMG_PIN);
    Serial.println(emgValue);
  }

  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      newData = true;
      break;
    } else {
      inputString += inChar;
    }
  }

  if (newData) {
    Serial.print("[DEBUG] Received: ");
    Serial.println(inputString);

    int separatorIndex = inputString.indexOf(':');
    if (separatorIndex != -1) {
      int label = inputString.substring(0, separatorIndex).toInt();
      int angle = inputString.substring(separatorIndex + 1).toInt();
      updateDisplayAndServo(label, angle);
    } else {
      Serial.println("Invalid format!");
    }

    inputString = "";
    newData = false;
  }
}

void updateDisplayAndServo(int label, int baseAngle) {
  int therapyAngle = min(baseAngle + 5, 90);

  String severity;
  switch (label) {
    case 0: severity = "No CTS"; break;
    case 1: severity = "Mild CTS"; break;
    case 2: severity = "Moderate CTS"; break;
    case 3: severity = "Severe CTS"; break;
    default: severity = "Unknown"; break;
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(severity);
  display.display();

  therapyServo.write(therapyAngle);
  Serial.print("[DEBUG] Moved servo to: ");
  Serial.println(therapyAngle);
}