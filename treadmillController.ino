#include <EEPROM.h>

const int TREADMILL = 9;
const int LED = 13;
const int EE_STORE = 0;

void setup() {
    Serial.begin(9600);

    int commandValue = EEPROM.read(EE_STORE);
    setOutputValue(commandValue);
}

void loop() {
    int commandValue = 0;

    while (Serial.available() > 0) {
        commandValue = Serial.parseInt();

        if (Serial.read() == '\n') {
            setOutputValue(commandValue);
            EEPROM.write(EE_STORE, commandValue);
        }
    }

    delay(500);
}

void setOutputValue(int commandValue) {
    commandValue = constrain(commandValue, 0, 100);
    int outputValue = map(commandValue, 0, 100, 0, 255);

    analogWrite(TREADMILL, outputValue);
    analogWrite(LED, outputValue);

    Serial.print("Output = " );
    Serial.print(commandValue);
    Serial.println("%");
}
