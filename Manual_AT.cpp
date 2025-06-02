#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial sim(7, 6);  // SIM800L: TX to D7, RX to D6

void setup() {
  Serial.begin(9600);  // Serial Monitor
  sim.begin(9600);     // SIM800L
  delay(1000);
  Serial.println("=== SIM800L AT Command Terminal ===");
  Serial.println("Type AT commands below:");
}

void loop() {
  // If data comes from Serial Monitor, send it to SIM800L
  if (Serial.available()) {
    sim.write(Serial.read());
  }

  // If data comes from SIM800L, send it to Serial Monitor
  if (sim.available()) {
    Serial.write(sim.read());
  }
}
