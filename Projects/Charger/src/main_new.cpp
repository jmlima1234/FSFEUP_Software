// #include <Arduino.h>
// #include <FlexCAN_T4.h>

// FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;

// void setup() {
//     Serial.begin(9600);

//     can1.begin();
//     can1.setBaudRate(125000);

//     CAN_message_t msg2;
//     msg2.id = 0x02204000;
//     msg2.buf[0] = 0x1B;
//     msg2.buf[1] = 0x00;
//     msg2.buf[2] = 0x00;
//     msg2.buf[3] = 0x69;
//     msg2.buf[4] = 0x12;
//     msg2.buf[5] = 0x61;
//     msg2.buf[6] = 0x12;
//     msg2.buf[7] = 0x93;

//     CAN_message_t msg1;
//     msg1.id = 0x02200000;
//     msg1.buf[0] = 0x01;
//     msg1.buf[1] = 0x04;
//     msg1.buf[2] = 0x00;
//     msg1.buf[3] = 0x00;
//     msg1.buf[4] = 0x00;
//     msg1.buf[5] = 0x00;
//     msg1.buf[6] = 0x00;
//     msg1.buf[7] = 0x00;

//     CAN_message_t msg3;
//     msg3.id = 0x02200000;
//     msg3.buf[0] = 0x10;
//     msg3.buf[1] = 0x02;
//     msg3.buf[2] = 0x00;
//     msg3.buf[3] = 0x00;
//     msg3.buf[4] = 0x00;
//     msg3.buf[5] = 0x07;
//     msg3.buf[6] = 0x41;
//     msg3.buf[7] = 0x9E;

//     can1.write(msg2);
//     can1.write(msg1);
//     can1.write(msg3);
// }

// void loop() {

//     CAN_message_t msg4;
//     msg4.id = 0x02200000;
//     msg4.buf[0] = 0x12;
//     msg4.buf[1] = 0x00;
//     msg4.buf[2] = 0x00;
//     msg4.buf[3] = 0x00;
//     msg4.buf[4] = 0x00;
//     msg4.buf[5] = 0x00;
//     msg4.buf[6] = 0x00;
//     msg4.buf[7] = 0x00;
//     can1.write(msg4);

//     CAN_message_t message3;

//     if (can1.read(message3)) {
//         Serial.print("Received message with ID 0x");
//         Serial.print(message3.id, HEX);
//         Serial.print(": ");
//         for (int i = 0; i < message3.len; i++) {
//             Serial.print(message3.buf[i]);
//         }
//         Serial.print('\n');
//     }

//   //Serial.println("teste");
//   delay(100);
// }