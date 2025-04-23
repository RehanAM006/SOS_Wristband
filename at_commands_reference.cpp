// Useful AT Commands for SIM800L setup and debugging:

// Basic Communication
AT             // Test communication
AT+CSQ         // Signal quality
AT+CREG?       // Network registration status
AT+COPS=?      // List available networks
AT+COPS=0      // Automatic operator selection
AT+COPS=1,2,"41001"  // Manual selection (e.g., Jazz)

// SMS
AT+CMGF=1      // Text mode
AT+CSCS="GSM"  // Set character set
AT+CMGS="+923xxxxxxxxx"  // Start SMS input (terminate with Ctrl+Z)

// SIM Status
AT+CPIN?       // Check SIM status

// Band Settings
AT+CBAND?      // Current band
AT+CBAND=?     // List available bands
AT+CBAND="EGSM_DCS"  // Set band (if supported)
