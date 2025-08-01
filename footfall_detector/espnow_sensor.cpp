/*
 * File: espnow_sensor_peer.cpp
 * Description: Implementation of ESP_NOW_Sensor_Peer methods
 */

#include "espnow_sensor.h"

// Create a broadcast peer object
ESP_NOW_Sensor_Peer broadcast_peer(ESPNOW_WIFI_CHANNEL, WIFI_IF_STA, nullptr);

ESP_NOW_Sensor_Peer::ESP_NOW_Sensor_Peer(uint8_t channel, wifi_interface_t iface, const uint8_t *lmk)
  : ESP_NOW_Peer(MacAddress(PEER_MAC_ADDR), channel, iface, lmk) {}

ESP_NOW_Sensor_Peer::~ESP_NOW_Sensor_Peer() {
    remove();
}

bool ESP_NOW_Sensor_Peer::begin() {
    if (!ESP_NOW.begin() || !add()) {
        log_e("Failed to init ESP-NOW or register peer");
        return false;
    }
    return true;
}

bool ESP_NOW_Sensor_Peer::send_message(const uint8_t *data, size_t len) {
    if (!send(data, len)) {
        log_e("Failed to broadcast message");
        return false;
    }
    return true;
}

void init_espnow_and_peer() {
    WiFi.mode(WIFI_STA);
    WiFi.setChannel(ESPNOW_WIFI_CHANNEL);
    while (!WiFi.STA.started()) {
        delay(100);
    }

    if (!broadcast_peer.begin()) {
        Serial.println("Failed to initialize ESP-NOW peer");
        delay(5000);
        ESP.restart();
    }
}