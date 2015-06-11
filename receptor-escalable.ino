#include <XBee.h>


XBee xbee;

void setup() {
  // put your setup code here, to run once:
  xbee = XBee();
  Serial.begin(9600);
  xbee.setSerial(Serial);
}
uint8_t payload[] = { 'H' };
XBeeAddress64 segunda = XBeeAddress64(0x13A200, 0x40A09C69);
//ZBTxRequest peti = ZBTxRequest(segunda, payload, sizeof(payload));

XBeeAddress64 primera = XBeeAddress64(0x13A200, 0x40A09D07);

XBeeAddress64 tercera = XBeeAddress64(0x13A200, 0x40A4D173);
//XBeeAddress64 addr64 = XBeeAddress64(0x0, 0xffff);
 
/**
XBeeAddress64 &addr64 = addr64
uint16_t addr16
uint8_t broadcastRadius = 1 / 0
uint8_t option ? 0
uint8_t *payload = payload
uint8_t payloadLength = sizeof(payload) 
uint8_t frameId  = 0
*/

//XBeeAddress64 addr64=XBeeAddress64(0x00000000, 0x0000ffff);
//ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));

uint16_t addr16=0xffff;
uint8_t broadcastradius=0;
uint8_t option=0;
uint8_t frameid=0;

ZBTxRequest primeraS=ZBTxRequest(primera,addr16,broadcastradius,option,payload,sizeof(payload),frameid);


ZBTxRequest segundaS=ZBTxRequest(segunda,addr16,broadcastradius,option,payload,sizeof(payload),frameid);


ZBTxRequest terceraS=ZBTxRequest(tercera,addr16,broadcastradius,option,payload,sizeof(payload),frameid);

int i=0;

void loop() {
¡

switch(i){
  case 0:
    xbee.send(primeraS);
    break;
   case 1:
     xbee.send(segundaS); 
     break;
    case 2:
      xbee.send(terceraS);
     break;
}
  i++;
  i=i%3;


  


delay(500);
}
