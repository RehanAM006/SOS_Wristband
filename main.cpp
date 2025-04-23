#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Pin setup
const int buttonPin = 4;
const int simRxPin = 7, simTxPin = 6;
const int gpsRxPin = 5, gpsTxPin = 3;

SoftwareSerial sim(simRxPin, simTxPin);  // SIM800L: TX to 7, RX to 6
SoftwareSerial gpsSerial(gpsRxPin, gpsTxPin);  // GPS: TX to 5, RX to 3

TinyGPSPlus gps;

const double HOME_LAT = 33.5826;
const double HOME_LNG = 73.1202;
const double SAFE_RADIUS_METERS = 50;

bool buttonPressed = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  sim.begin(9600);
  gpsSerial.begin(9600);

  delay(2000);
  sendCommand("AT");
  sendCommand("AT+CMGF=1");
  sendCommand("AT+CSCS=\"GSM\"");
}

void loop() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (digitalRead(buttonPin) == LOW && !buttonPressed) {
    buttonPressed = true;
    delay(50); // debounce

    if (gps.location.isValid()) {
      double lat = gps.location.lat();
      double lng = gps.location.lng();
      double distance = TinyGPSPlus::distanceBetween(lat, lng, HOME_LAT, HOME_LNG);

      if (distance > SAFE_RADIUS_METERS) {
        String link = "https://maps.google.com/?q=" + String(lat, 6) + "," + String(lng, 6);
        sendSMS("+923xxxxxxxxx", "ALERT! Device moved from home: " + link);
      } else {
        sendSMS("+923xxxxxxxxx", "Device is within safe zone.");
      }
    } else {
      sendSMS("+923xxxxxxxxx", "GPS not fixed yet.");
    }
  }

  if (digitalRead(buttonPin) == HIGH) {
    buttonPressed = false;
  }
}

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
