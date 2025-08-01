/* 
  Footfall detector
  Nafih Ahammed - 2025

  An open‑source solution building and deploying geophone‑based footfall detectors. 
  Each detector node uses an ESP32‑C6 microcontroller, an ADS1115 16‑bit analog‑to‑digital converter (ADC), 
  and a TLC272 low‑noise amplifier to sense ground vibrations.
  Detector nodes communicate wirelessly via ESP‑NOW to a Raspberry Pi control center that collects, 
  timestamps, and visualizes footfall events in real time. 

*/
#include "espnow_sensor.h"

/* Global Variables */

uint32_t msg_count = 0;

/* Main */

void setup() {
  Serial.begin(115200);
  
  init_espnow_and_peer();

  Serial.println("Setup complete. Broadcasting messages every 5 seconds.");
}

void loop() {
  // Broadcast a message to all devices within the network
  char data[32];
  snprintf(data, sizeof(data), "Hello, World! #%lu", msg_count++);

  Serial.printf("Sending to gateway: %s\n", data);

  if (!broadcast_peer.send_message((uint8_t *)data, sizeof(data))) {
    Serial.println("Failed to broadcast message");
  }

  delay(5000);
}
