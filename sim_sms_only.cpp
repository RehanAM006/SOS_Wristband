#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial sim(7, 6);  // SIM800L: TX to 7, RX to 6

void setup() {
  Serial.begin(9600);
  sim.begin(9600);

  delay(2000);
  sendCommand("AT");
  sendCommand("AT+CMGF=1");
  sendCommand("AT+CSCS=\"GSM\"");
  sendSMS("+923xxxxxxxxx", "Test message from SIM800L");
}

void loop() {}

void sendCommand(String cmd) {
  sim.println(cmd);
  delay(500);
  while (sim.available()) {
    Serial.write(sim.read());
  }
}

void sendSMS(String number, String message) {
  sim.print("AT+CMGS=\"");
  sim.print(number);
  sim.println("\"");
  delay(1000);
  sim.print(message);
  delay(500);
  sim.write(26);
  delay(2000);
}
