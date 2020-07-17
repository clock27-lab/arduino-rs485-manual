#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);


/*

KONEKSI

PIN ARDUINO <=============> MODUL UART TO RS485

PIN 10      <=============> PIN RX
PIN 11      <=============> PIN TX
PIN 5V      <=============> PIN VCC
PIN GND      <=============> PIN GND


*/


void setup() {
  
  Serial.begin(9600);
  mySerial.begin(9600);
  delay (2000);
  Serial.println("ARDUINO KONEKSI MODULE RS485");
  delay (2000);
  Serial.println("ARDUINO KIRIM KE RS485");
  mySerial.println("ARDUINO 2 KIRIM KE ARDUINO 1");

}

void loop() { // run over and over
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
