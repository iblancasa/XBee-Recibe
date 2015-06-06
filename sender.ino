#include <XBee.h>


XBee xbee;

void setup() {

  xbee = XBee();
  Serial.begin(9600);
  xbee.setSerial(Serial);
}
uint8_t payload[] = { 'H', 'i' };
XBeeAddress64 addr64 = XBeeAddress64(0x13A200, 0x40A09D07);
//XBeeAddress64 addr64 = XBeeAddress64(0x0, 0xffff);
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));

XBeeAddress64 segunda = XBeeAddress64(0x13A200, 0x40A09C69);
ZBTxRequest peti = ZBTxRequest(segunda, payload, sizeof(payload));

void loop() {


xbee.send(zbTx);
xbee.send(peti);

delay(1000);
}
