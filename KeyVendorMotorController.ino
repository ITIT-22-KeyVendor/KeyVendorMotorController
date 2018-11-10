#include "SoftwareSerial.h"

SoftwareSerial mainControllerSerial(3, 4);
String input = "";

void setup() {
  Serial.begin(9600);
  mainControllerSerial.begin(9600);
  delay(300);
  
  Serial.println("Motor controller is ready");
}
void loop() {
  if (mainControllerSerial.available()) {
    input = "";
    while(mainControllerSerial.available())
      input += char(mainControllerSerial.read());
    Serial.print("Received from main controller: ");
    Serial.println(input);
  }
  if (Serial.available()) {
    input = "";
    while(Serial.available())
      input += char(Serial.read());
    Serial.print("Received from user: ");
    Serial.println(input);
  }  
}
