

// CODE FOR FINDING MAC-ADDRESS OF ESP32

// #include "WiFi.h"
// void setup() {
//   Serial.begin(115200);
//   WiFi.mode(WIFI_MODE_STA);
//   Serial.println(WiFi.macAddress());
// }

// void loop(){
// }

#include <esp_now.h>
#include <WiFi.h>

typedef struct struct_message {
  char a[32];
  int b;
  float c;
  bool d;
} struct_message;

struct_message myData;

esp_now_peer_info_t peerInfo;

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Data received: ");
  Serial.println(len);
  Serial.print("Character Value: ");
  Serial.println(myData.a);
  // Serial.print("Integer Value: ");
  // Serial.println(myData.b);
  // Serial.print("Float Value: ");
  // Serial.println(myData.c);
  // Serial.print("Bool Value: ");
  // Serial.println(myData.d);
  // Serial.println();
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-Now");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);

  // Add the MAC address of the sender
  uint8_t senderMacAddress[] = {Mac address};
  memcpy(peerInfo.peer_addr, senderMacAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  // // Sender part of the code
  // strcpy(myData.a, "Hello from ESP32!");
  // myData.b = 42;
  // myData.c = 3.14;
  // myData.d = true;

  // esp_err_t result = esp_now_send(peerInfo.peer_addr, (uint8_t*)&myData, sizeof(myData));

  // if (result == ESP_OK) {
  //   Serial.println("Sending Confirmed");
  // } else {
  //   Serial.println("Sending Error");
  // }

  // delay(2000);
}

