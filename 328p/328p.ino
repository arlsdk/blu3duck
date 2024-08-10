//arlsdk - blu3duck 328p microcode
#include <SoftwareSerial.h>
SoftwareSerial Blueserial(7, 8);

const String PIN = "yourpincode";
String enteredPIN = "";
bool pinVerified = false;

void setup() {
  Serial.begin(115200);
  Blueserial.begin(9600);
  Serial.println("Blu3duck 1.0 IOMCU, init...");
}

void loop() {
    if (Blueserial.available()) {
      String command = Blueserial.readStringUntil('\n');
      command.trim();
    if(command == "lock"){
      pinVerified =false;
    }

    if (!pinVerified) {
      if (command == PIN) {
        pinVerified = true;
      } else {
      }
    } else {
      Serial.println(command);
    }
  }
}
