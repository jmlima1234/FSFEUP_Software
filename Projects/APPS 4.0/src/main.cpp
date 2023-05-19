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
  int val = analogRead(14);
  // Create a CAN message with the pedal value and the desired message ID
  CAN_message_t message;  
  message.id = MESSAGE_ID;
  message.len = 1;
  message.buf[0] = val;
  // Send the message over the CAN bus
  can1.write(message);
  CAN_message_t message2;
  // Check if there's a new message available and read it if there is
  if (can1.read(message2)) {
    // Check that the message ID matches the one we're listening for
    if (message2.id == 0x124) {
      analogWrite(15,message2.buf[0]);
    }
  }
  delay(10);
}

