/*
 * File: espnow_sensor_peer.h
 * Description: Declaration of ESP-NOW broadcast peer class
 */

#ifndef ESPNOW_SENSOR_H
#define ESPNOW_SENSOR_H

#include "ESP32_NOW.h"
#include "WiFi.h"
#include "MacAddress.h"
#include <esp_mac.h>

#define ESPNOW_WIFI_CHANNEL 6

// Configure the peer MAC address (e.g. E4:B3:23:B6:A8:08)
static const uint8_t PEER_MAC_ADDR[6] = {0xE4, 0xB3, 0x23, 0xB6, 0xA8, 0x08};

// Creating a new class that inherits from the ESP_NOW_Peer class is required.
class ESP_NOW_Sensor_Peer : public ESP_NOW_Peer {
public:
    ESP_NOW_Sensor_Peer(uint8_t channel = ESPNOW_WIFI_CHANNEL,
                        wifi_interface_t iface = WIFI_IF_STA,
                        const uint8_t *lmk = nullptr);
    ~ESP_NOW_Sensor_Peer();

    // Initialize ESP-NOW and register peer
    bool begin();

    // Broadcast a message
    bool send_message(const uint8_t *data, size_t len);
};
// Extern instance for use across translation units
extern ESP_NOW_Sensor_Peer broadcast_peer;

/* Single function to initialize Wi-Fi and ESP-NOW */
void init_espnow_and_peer();

#endif // ESPNOW_SENSOR_H