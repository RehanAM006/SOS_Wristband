# SOS_Wristband

# SOS GPS Tracker with SIM800L and MIT App Integration

This project implements a safety alert system using GPS + GSM + Arduino + MIT App Inventor. It sends an SMS with Google Maps location when a button is pressed and the device has moved away from a fixed HOME location.

## 📦 Contents

| File | Description |
|------|-------------|
| `src/main.cpp` | Full project: GPS + SIM800L + Button |
| `src/sim_sms_only.cpp` | Standalone SMS sending example |
| `src/at_commands_reference.cpp` | AT Commands with important reference |

## 🔧 Setup

### Hardware

- SIM800L V2.0 5V GSM GPRS Module
- NEO-6M GPS Module
- Arduino (Uno/Nano)
- Push button
- Power supply: Stable 5V/2A recommended

### Connections

| Module | Arduino Pin |
|--------|-------------|
| SIM800L TX | D7 |
| SIM800L RX | D6 |
| GPS TX | D5 |
| GPS RX | D3 |
| Button | D4 |

### Software

- PlatformIO (VS Code)
- Arduino framework
- TinyGPS++ Library

Install TinyGPS++ via `platformio.ini`:

```ini
lib_deps = mikalhart/TinyGPSPlus
```

## 📱 MIT App

The parent app can parse the SMS and open Google Maps with the embedded link.

## 📝 License

MIT License
