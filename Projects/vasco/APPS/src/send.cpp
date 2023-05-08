#include <FlexCAN_T4.h>

// Set up CAN bus with a bitrate of 500 kbps
FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can0(500000);

void setup() {
  Serial.begin(9600);
  while (!Serial) {}

  // Initialize the CAN bus
  can0.begin();

  // Set up a CAN message to send to the other microcontroller
  CAN_message_t msg;
  msg.id = 0x123;
  msg.len = 8;
  msg.buf[0] = 'H';
  msg.buf[1] = 'e';
  msg.buf[2] = 'l';
  msg.buf[3] = 'l';
  msg.buf[4] = 'o';
  msg.buf[5] = '!';
  msg.buf[6] = 0x00;
  msg.buf[7] = 0x00;

  // Send the CAN message
  can0.write(msg);
}

void loop() {
  // Check if there are any CAN messages available
  if (can0.available()) {
    // Read the CAN message
    CAN_message_t msg;
    can0.read(msg);

    // Print the received message
    Serial.print("Received message with ID 0x");
    Serial.print(msg.id, HEX);
    Serial.print(": ");
    for (int i = 0; i < msg.len; i++) {
      Serial.print((char)msg.buf[i]);
    }
    Serial.println();
  }
}
