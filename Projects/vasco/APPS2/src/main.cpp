#include <Arduino.h>
#include <FlexCAN_T4.h>

// Define the CAN message ID that we're listening for
const uint32_t MESSAGE_ID = 0x123;

// Set up the FlexCAN object
FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  // Initialize the CAN bus
  can1.begin();
  can1.setBaudRate(1000000);
}

void loop() {
  // Check if there's a new message available and read it if there is
  CAN_message_t message;
  if (can1.read(message)) {
    // Check that the message ID matches the one we're listening for
    if (message.id == MESSAGE_ID) {
      Serial1.print("Received message with ID 0x");
      Serial1.print(message.id, HEX);
      Serial1.print(": ");
      for (int i = 0; i < message.len; i++) {
        Serial1.print((char)message.buf[i]);
      }
      Serial1.println();
    }
  }
}

// Do I need a function to handle the pedal value?
