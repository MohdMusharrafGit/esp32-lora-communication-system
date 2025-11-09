#include <HardwareSerial.h>

// UART2 pins for LoRa communication
const byte RXD2 = 16;  // ESP32 RX2
const byte TXD2 = 17;  // ESP32 TX2

HardwareSerial mySerial(2);  // Use UART2 (Serial2)

// Pin definitions
const int button1 = 4;
const int button2 = 5;
const int led1 = 12;  // Blinks when sending
const int led2 = 14;  // Blinks when ACK received

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600, SERIAL_8N1, RXD2, TXD2);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

  Serial.println("Sender Ready...");
}

void loop() {
  // --- Button 1 Pressed ---
  if (digitalRead(button1) == LOW) {
    Serial.println("Button 1 pressed -> Sending 10");

    // Blink LED1 to indicate sending
    digitalWrite(led1, HIGH);
    mySerial.write(10);
    delay(200);
    digitalWrite(led1, LOW);

    // Wait for ACK 20
    unsigned long startTime = millis();
    bool ackReceived = false;
    while (millis() - startTime < 5000) {  // 5s timeout
      if (mySerial.available()) {
        byte ack = mySerial.read();
        if (ack == 20) {
          Serial.println("Received ACK 20");
          // Blink LED2 to indicate ACK received
          digitalWrite(led2, HIGH);
          delay(200);
          digitalWrite(led2, LOW);
          ackReceived = true;
          break;
        }
      }
    }
    if (!ackReceived) {
      Serial.println("No ACK (20) received!");
    }
  }

  // --- Button 2 Pressed ---
  if (digitalRead(button2) == LOW) {
    Serial.println("Button 2 pressed -> Sending 30");

    // Blink LED1 to indicate sending
    digitalWrite(led1, HIGH);
    mySerial.write(30);
    delay(200);
    digitalWrite(led1, LOW);

    // Wait for ACK 40
    unsigned long startTime = millis();
    bool ackReceived = false;
    while (millis() - startTime < 5000) {  // 5s timeout
      if (mySerial.available()) {
        byte ack = mySerial.read();
        if (ack == 40) {
          Serial.println("Received ACK 40");
          // Blink LED2 to indicate ACK received
          digitalWrite(led2, HIGH);
          delay(200);
          digitalWrite(led2, LOW);
          ackReceived = true;
          break;
        }
      }
    }
    if (!ackReceived) {
      Serial.println("No ACK (40) received!");
    }
  }
}
