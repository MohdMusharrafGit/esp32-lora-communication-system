#include <HardwareSerial.h>

// UART2 pins for LoRa communication
const byte RXD2 = 16;  // ESP32 RX2
const byte TXD2 = 17;  // ESP32 TX2

HardwareSerial mySerial(2);  // Use UART2 (Serial2)

// Pin for buzzer
const int buzzer = 25;

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600, SERIAL_8N1, RXD2, TXD2);

  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  Serial.println("Receiver Ready...");
}

void loop() {
  if (mySerial.available()) {
    byte received = mySerial.read();
    Serial.print("Received: ");
    Serial.println(received);

    // --- Case 1: Turn ON Buzzer ---
    if (received == 10) {
      Serial.println("Turning ON buzzer...");
      digitalWrite(buzzer, HIGH);
      delay(100); // short delay for reliable ACK timing
      Serial.println("Sending ACK 20");
      mySerial.write(20);
    }

    // --- Case 2: Turn OFF Buzzer ---
    else if (received == 30) {
      Serial.println("Turning OFF buzzer...");
      digitalWrite(buzzer, LOW);
      delay(100); // short delay for reliable ACK timing
      Serial.println("Sending ACK 40");
      mySerial.write(40);
    }
  }
}
