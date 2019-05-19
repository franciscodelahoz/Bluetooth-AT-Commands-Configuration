#include <Arduino.h>
#include <SoftwareSerial.h>

// This is a Script to configure the HC-05 module using a arduino

// CONNECT HC-05 RX PIN TO ARDUINO 11 PIN | CONNECT HC-05 TX PIN TO ARDUINO 10 PIN
SoftwareSerial BluetoothSerial(10, 11);

void setup() {
	pinMode(9, OUTPUT); //CONNECT HC-05 EN PIN TO ARDUINO 9 PIN
	digitalWrite(9, HIGH); // Pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode

	Serial.begin(9600);
	Serial.println("Enter AT commands:");

	BluetoothSerial.begin(38400); // HC-05 default speed in AT command mode
}

void loop() {
	// Keep reading from HC-05 and send to Arduino Serial Monitor
	if (BluetoothSerial.available()) {
		Serial.write(BluetoothSerial.read());
	}

	// Keep reading from Arduino Serial Monitor and send to HC-05
	if (Serial.available()) {
		BluetoothSerial.write(Serial.read());
	}
}
