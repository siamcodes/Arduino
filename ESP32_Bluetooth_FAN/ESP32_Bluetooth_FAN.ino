#include <SoftwareSerial.h>
SoftwareSerial mySerial(1,3);  //(Tx, Rx)

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

int speed1 = 21;
int speed2 = 22;
int speed3 = 23;
int stop1 = 19;

void setup() {
  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);
  pinMode(speed3, OUTPUT);
  pinMode(stop1, OUTPUT);  
  mySerial.begin(9600);
  mySerial.begin('ESP32');
  Serial.begin(9600);
  
}

void loop() {
   if(mySerial.available() > 0){
      char ch = mySerial.read();
      if(ch == 'A'){
        digitalWrite(speed1, HIGH);
        digitalWrite(speed2, LOW);
        digitalWrite(speed3, LOW);
        Serial.println("Speed1 on");
      }else if(ch == 'B'){
        digitalWrite(speed1, LOW);
        digitalWrite(speed2, HIGH);
        digitalWrite(speed3, LOW);
        Serial.println("Speed2 on");
      }else if(ch == 'C'){
        digitalWrite(speed1, LOW);
        digitalWrite(speed2, LOW);
        digitalWrite(speed3, HIGH);
        Serial.println("Speed3 on");
      }else if(ch == 'Z'){
        digitalWrite(speed1, LOW);
        digitalWrite(speed2, LOW);
        digitalWrite(speed3, LOW);
        Serial.println("OFF ALL");
      }else{
        digitalWrite(speed1, LOW);
        digitalWrite(speed2, LOW);
        digitalWrite(speed3, LOW);
        Serial.println("Don't Select");
      }
   }
   Serial.println();
   delay(1000);
}
