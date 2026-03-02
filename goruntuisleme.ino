#include <Servo.h> 
//Servo motorlar 
Servo servo1; //pin9
Servo servo2; //pin10
Servo servo3; //pin11
Servo servo4; //pin12


//Bant motoru pinleri 
int ENA=3;
int IN1=4;
int IN2=5;

//TCS3200 PİNLERİ 
const int S0=6;
const int S1=7;
const int S2=A0;
const int S3=A1;
const int sensorOut=A2;

//Renk okuma 
int red, black, white;


void setup() {
servo1.attach(9);
servo2.attach(10);
servo3.attach(11);
servo4.attach(12);

//Bant motoru çıkış:
pinMode(ENA, OUTPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);

//RENK SENSÖRÜ PİNLERİ 
pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT); 
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);
pinMode(sensorOut, INPUT);

//TCS3200 FREKANS AYARI 
digitalWrite(S0, HIGH);
digitalWrite(S1, LOW);

  }

void loop() {
  // RENK OKU 
readColor();

//kırmızı algılandıysa 
if (red> black+ 20 && red> white+ 20) {
 stopBelt();
 pickRedCube();
 startBelt();

    }
delay(100); 
  }

void readColor() {

  //kırmızı 
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  red= pulseIn(sensorOut, LOW);
  
  //SİYAH 
  digitalWrite(S2, HIGH);
  digitalWrite(S3, LOW);
  black= pulseIn(sensorOut, LOW);

  //BEYAZ 
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  white= pulseIn(sensorOut, LOW);
  Serial.print ("R"); Serial.print(red);
  Serial.print ("B");
  Serial.print(black);
  Serial.print ("W");
  Serial.print(white);

Serial.print("Red: "); Serial.println(red);
Serial.print("Black: "); Serial.println(black);
Serial.print("White: "); Serial.println(white);

// küpü bıraktıktan sonra başlangıca dön
servo4.write(90);   // bırak
delay(500);

servo2.write(90);   // düzleş
servo3.write(90);
delay(500);

servo1.write(90);   // tabanı başlangıç açısına getir
delay(500);



}
void startBelt() {
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
analogWrite(ENA, 200); //HIZ AYARI 

}
 
 void stopBelt() {
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
analogWrite(ENA, 0);

}


void pickRedCube() {
// 1) Küpü alma pozisyonuna eğil
  servo2.write(95);
  servo3.write(75);
  delay(500);

  // 2) Küpü tut
  servo4.write(25); //tutucu kapat
  delay(500);

  // 3) Küpü kaldır
  servo2.write(70);
  servo3.write(90);
  delay(800);

  // 4) Küpü bırak
  servo4.write(90); //bırak
  delay(500);

  // 5) Başlangıca dön
  servo2.write(90);
  servo3.write(90);
  servo1.write(90);
  delay(500);

}


