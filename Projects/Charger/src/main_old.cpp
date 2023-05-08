#include <Arduino.h>
#include <FlexCAN_T4.h>

FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;

void setup() {
  Serial.begin(9600);

  can1.begin();
  can1.setBaudRate(125000);
  CAN_message_t msg5; // power off module
  msg5.id = 0x02204000;
  msg5.len = 8;
  msg5.flags.extended = 1;
  msg5.buf[0] = 0x10;
  msg5.buf[1] = 0x04;
  msg5.buf[2] = 0x00;
  msg5.buf[3] = 0x00;
  msg5.buf[4] = 0x00;
  msg5.buf[5] = 0x00;
  msg5.buf[6] = 0x00;
  msg5.buf[7] = 0x01;
  can1.write(msg5);
}

void loop() {

  // CAN_message_t msg; // power on module
  // msg.id = 0x02204000;
  // msg.len = 8;
  // msg.flags.extended = 1;
  // msg.buf[0] = 0x10;
  // msg.buf[1] = 0x04;
  // msg.buf[2] = 0x00;
  // msg.buf[3] = 0x00;
  // msg.buf[4] = 0x00;
  // msg.buf[5] = 0x00;
  // msg.buf[6] = 0x00;
  // msg.buf[7] = 0x00;
  

  // can1.write(msg);

  CAN_message_t msg2; // set an output reference of 200V
  msg2.flags.extended = 1;
  msg2.id = 0x02204000;
  msg2.len = 8;
  msg2.buf[0] = 0x10;
  msg2.buf[1] = 0x02;
  msg2.buf[2] = 0x00;
  msg2.buf[3] = 0x00;
  msg2.buf[4] = 0x00;
  msg2.buf[5] = 0x03;
  msg2.buf[6] = 0x0D;
  msg2.buf[7] = 0x40;
  can1.write(msg2);

  CAN_message_t msg3; // set an output reference of 2A 
  msg3.flags.extended = 1;
  msg3.id = 0x02204000;
  msg3.len = 8;
  msg3.buf[0] = 0x10;
  msg3.buf[1] = 0x03;
  msg3.buf[2] = 0x00;
  msg3.buf[3] = 0x00;
  msg3.buf[4] = 0x00;
  msg3.buf[5] = 0x00;
  msg3.buf[6] = 0x07;
  msg3.buf[7] = 0xD0;

  can1.write(msg3);

  CAN_message_t msg4; //read status flag
  msg4.id = 0x02204000;
  msg4.flags.extended = 1;
  msg4.len = 8;
  msg4.buf[0] = 0x12;
  msg4.buf[1] = 0x08;
  msg4.buf[2] = 0x00;
  msg4.buf[3] = 0x00;
  msg4.buf[4] = 0x00;
  msg4.buf[5] = 0x00;
  msg4.buf[6] = 0x00;
  msg4.buf[7] = 0x00;
  
  can1.write(msg4);  

  CAN_message_t message2;

  if (can1.read(message2)) {
    Serial.print("Received message with ID 0x");
    Serial.print(message2.id, HEX);
    Serial.print(": ");
    for (int i = 0; i < message2.len; i++) {
      Serial.print(message2.buf[i]);
    }
    Serial.print('\n');
  }
  //Serial.println("teste");


}


