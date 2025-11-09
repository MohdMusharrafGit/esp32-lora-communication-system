# ESP32 LoRa Communication System

This project implements a simple **LoRa-based wireless communication** between two ESP32 boards using UART.  
It’s built on a custom PCB with one **Sender unit** and one **Receiver unit**.

---

## 🔹 Overview
- The **Sender** sends commands via LoRa when a button is pressed.
- The **Receiver** controls a buzzer and sends acknowledgments back.
- **LEDs** on the sender indicate sending and acknowledgment events.

---

## 🔹 Communication Logic
| Action | Sender Command | Receiver Action | ACK Sent |
|---------|----------------|----------------|-----------|
| Button 1 Press | 10 | Buzzer ON | 20 |
| Button 2 Press | 30 | Buzzer OFF | 40 |

---

## 🔹 Hardware Summary
- ESP32 × 2 (Sender & Receiver)
- LoRa module × 2  
- LEDs, Push Buttons, Buzzer  
- LM2596 voltage regulator (on PCB)

---

## 🔹 Code Files
- `sender_code.ino` — Handles button input, sending, and LED blinking.
- `receiver_code.ino` — Controls buzzer and sends acknowledgments automatically.


---

## 🔹 Developed by
**Mohd Musharraf**  
ESP32–LoRa Custom PCB Project  
Central University of Jammu
