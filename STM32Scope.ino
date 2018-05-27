//
// This is a placeholder for a more sophisticated data source for OsciPrime_mod.
// Copyright (c) Alexander Pruss
// MIT License
//

#define CH1 PA0
#define CH2 PA1

#ifdef STM32GENERIC
#define VID 0x81b1 // randomly generated
#define PID 0x7ce3 // randomly generated

extern uint8_t USBD_CDC_DeviceDesc[];

void setVIDPID() {  
  USBD_CDC_DeviceDesc[8] = VID&0xFF;
  USBD_CDC_DeviceDesc[9] = VID>>8;
  USBD_CDC_DeviceDesc[10] = PID&0xFF;
  USBD_CDC_DeviceDesc[11] = PID>>8;
}
#endif

void setup() {
  setVIDPID();
  pinMode(CH1,INPUT);
  pinMode(CH2,INPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.write(datum);
}
