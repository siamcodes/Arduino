//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int speed1 = 21;
int speed2 = 22;
int speed3 = 23;
int stop1 = 19;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32-BT"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);
  pinMode(speed3, OUTPUT);
  pinMode(stop1, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  
  if (SerialBT.available()>0) {
    Serial.write(SerialBT.read());
    char ch = SerialBT.read();
    if (ch == 'A') {
      digitalWrite(speed1, HIGH);
      digitalWrite(speed2, LOW);
      digitalWrite(speed3, LOW);
      Serial.println("Speed1 on");
    } else if (ch == 'B') {
      digitalWrite(speed1, LOW);
      digitalWrite(speed2, HIGH);
      digitalWrite(speed3, LOW);
      Serial.println("Speed2 on");
    } else if (ch == 'C') {
      digitalWrite(speed1, LOW);
      digitalWrite(speed2, LOW);
      digitalWrite(speed3, HIGH);
      Serial.println("Speed3 on");
    } else if (ch == 'Z') {
      digitalWrite(speed1, LOW);
      digitalWrite(speed2, LOW);
      digitalWrite(speed3, LOW);
      Serial.println("OFF ALL");
    } else {
      digitalWrite(speed1, LOW);
      digitalWrite(speed2, LOW);
      digitalWrite(speed3, LOW);
      // Serial.println("Don't Select");
    }
  }

  Serial.println();
  delay(1000);
}
