#include "Nextion.h"
#include <Adafruit_NeoPixel.h>    // importa libreria
Adafruit_NeoPixel tira = Adafruit_NeoPixel(180, 10, NEO_GRB + NEO_KHZ800); // creacion de objeto "tira"
Adafruit_NeoPixel tira1 = Adafruit_NeoPixel(60, 3, NEO_GRB + NEO_KHZ800); // creacion de objeto "tira1"
#include <Stepper.h>
//#include "Wire.h"      //incluye libreria i2c      
//SoftwareSerial S2(11,10);
NexButton bpos = NexButton(1, 1, "bpos");
NexButton btn1 = NexButton(1, 2, "btn1");
NexButton btn2 = NexButton(1, 3, "btn2");
NexButton btn3 = NexButton(1, 4, "btn3");
NexButton bon = NexButton(1, 5, "bon");
NexButton boff = NexButton(1, 6, "boff");
NexButton btnr = NexButton(1, 7, "btnr");
NexButton btnv = NexButton(1, 8, "btnv");
NexButton btna = NexButton(1, 9, "btna");
NexButton btnm = NexButton(1, 10, "btnm");
NexButton btnam = NexButton(1, 11, "btnam");
NexButton btnc = NexButton(1, 12, "btnc");
NexButton btnon1 = NexButton(2, 5, "btnon1");
NexButton btnoff1 = NexButton(2, 6, "btnoff1");
NexButton btnon2 = NexButton(2, 14, "btnon2");
NexButton btnoff2 = NexButton(2, 15, "btnoff2");
NexSlider slidervel = NexSlider(2, 1, "slidervel");
NexSlider sliderr = NexSlider(2, 7, "sliderr");
NexSlider sliderv = NexSlider(2, 10, "sliderv");
NexSlider slidera = NexSlider(2, 12, "slidera");
NexSlider sliderb = NexSlider(1, 18, "sliderb");
NexButton btnr2 = NexButton(3, 1, "btnr2");
NexButton btnv2 = NexButton(3, 2, "btnv2");
NexButton btna2 = NexButton(3, 3, "btna2");
NexButton btnm2 = NexButton(3, 4, "btnm2");
NexButton btnam2 = NexButton(3, 5, "btnam2");
NexButton btnc2 = NexButton(3, 6, "btnc2");
NexButton btnb2 = NexButton(3, 21, "btnb2");
NexButton bon3 = NexButton(3, 9, "bon3");
NexButton boff3 = NexButton(3, 10, "boff3");
NexSlider sliderr2 = NexSlider(3, 15, "sliderr2");
NexSlider sliderv2 = NexSlider(3, 16, "sliderv2");
NexSlider slidera2 = NexSlider(3, 17, "slidera2");
NexSlider sliderb2 = NexSlider(3, 7, "sliderb2");

uint32_t valvel = 0;
uint32_t valr = 0;
uint32_t valv = 0;
uint32_t vala = 0;
uint32_t valbrillo = 0;
uint32_t valr2 = 0;
uint32_t valv2 = 0;
uint32_t vala2 = 0;
uint32_t valbrillo2 = 0;

int numled = 180;
int numled1 = 60;
int brillo = 0;
int brillo2 = 0;
#define REED_IN_PIN 11
int magneticPresence = LOW;
const int pasosPorRevolucion = 2502;
Stepper motor (pasosPorRevolucion, 8, 9);


NexTouch *nex_listen_list[] =
{
  &bpos,
  &btn1,
  &btn2,
  &btn3,
  &bon,
  &boff,
  &btnr,
  &btnv,
  &btna,
  &btnm,
  &btnam,
  &btnc,
  &btnon1,
  &btnoff1,
  &btnon2,
  &btnoff2,
  &btnr2,
  &btnv2,
  &btna2,
  &btnm2,
  &btnam2,
  &btnc2,
  &btnb2,
  &bon3,
  &boff3,
  NULL
};

void posicion() {
  magneticPresence = digitalRead(REED_IN_PIN);
  if (magneticPresence == HIGH) {
    for (int i = 0; magneticPresence == HIGH; i++) {
      magneticPresence = digitalRead(REED_IN_PIN);
      motor.setSpeed(90);
      motor.step(10 + i);
    }
  }

  if (magneticPresence == LOW) {
    motor.setSpeed(90);
    motor.step(0);
  }
}

void opc1() {
  for (int i = 0; i < 27; i++) {//53
    motor.setSpeed(40);
    motor.step(pasosPorRevolucion);
  }
}

void opc2() {
  for (int i = 0; i < 27; i++) {
    motor.setSpeed(20);
    motor.step(pasosPorRevolucion);
  }
}

void opc3() {
  for (int i = 0; i < 27; i++) {
    motor.setSpeed(10);
    motor.step(pasosPorRevolucion);
  }
}

void on() {
  sliderb.getValue(&valbrillo);
  brillo = (valbrillo * 1.5);
  tira.clear();       // restablece todos los pixeles en apagado
  tira.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled; i++) { // bucle para recorrer posiciones 0 a 7
    tira.setPixelColor(i, 255, 255, 255);   // cada pixel en color azul (posicion,R,G,B)
    tira.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }

  tira1.clear();       // restablece todos los pixeles en apagado
  tira1.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled1; i++) { // bucle para recorrer posiciones 0 a 7
    tira1.setPixelColor(i, 255, 255, 255);   // cada pixel en color azul (posicion,R,G,B)
    tira1.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }

}

void off() {
  tira.clear();
  tira.show();      // muestra datos en pixel

  tira1.clear();
  tira1.show();      // muestra datos en pixel
}

void rojo() {
  sliderb.getValue(&valbrillo);
  brillo = (valbrillo * 1.5);
  tira.clear();       // restablece todos los pixeles en apagado
  tira.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled; i++) { // bucle para recorrer posiciones 0 a 7
    tira.setPixelColor(i, 255, 0, 0);   // cada pixel en color azul (posicion,R,G,B)
    tira.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }

  tira1.clear();       // restablece todos los pixeles en apagado
  tira1.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled1; i++) { // bucle para recorrer posiciones 0 a 7
    tira1.setPixelColor(i, 255, 0, 0);   // cada pixel en color azul (posicion,R,G,B)
    tira1.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }
}

void verde() {
  sliderb.getValue(&valbrillo);
  brillo = (valbrillo * 1.5);
  tira.clear();       // restablece todos los pixeles en apagado
  tira.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled; i++) { // bucle para recorrer posiciones 0 a 7
    tira.setPixelColor(i, 0, 255, 0);   // cada pixel en color azul (posicion,R,G,B)
    tira.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }

  tira1.clear();       // restablece todos los pixeles en apagado
  tira1.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled1; i++) { // bucle para recorrer posiciones 0 a 7
    tira1.setPixelColor(i, 0, 255, 0);   // cada pixel en color azul (posicion,R,G,B)
    tira1.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }
}

void azul() {
  sliderb.getValue(&valbrillo);
  brillo = (valbrillo * 1.5);
  tira.clear();       // restablece todos los pixeles en apagado
  tira.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled; i++) { // bucle para recorrer posiciones 0 a 7
    tira.setPixelColor(i, 0, 0, 255);   // cada pixel en color azul (posicion,R,G,B)
    tira.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }

  tira1.clear();       // restablece todos los pixeles en apagado
  tira1.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled1; i++) { // bucle para recorrer posiciones 0 a 7
    tira1.setPixelColor(i, 0, 0, 255);   // cada pixel en color azul (posicion,R,G,B)
    tira1.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }
}

void magenta() {
  sliderb.getValue(&valbrillo);
  brillo = (valbrillo * 1.5);
  tira.clear();       // restablece todos los pixeles en apagado
  tira.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled; i++) { // bucle para recorrer posiciones 0 a 7
    tira.setPixelColor(i, 255, 0, 128);   // cada pixel en color azul (posicion,R,G,B)
    tira.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }

  tira1.clear();       // restablece todos los pixeles en apagado
  tira1.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled1; i++) { // bucle para recorrer posiciones 0 a 7
    tira1.setPixelColor(i, 255, 0, 128);   // cada pixel en color azul (posicion,R,G,B)
    tira1.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }
}

void amarillo() {
  sliderb.getValue(&valbrillo);
  brillo = (valbrillo * 1.5);
  tira.clear();       // restablece todos los pixeles en apagado
  tira.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled; i++) { // bucle para recorrer posiciones 0 a 7
    tira.setPixelColor(i, 255, 255, 0);   // cada pixel en color azul (posicion,R,G,B)
    tira.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }

  tira1.clear();       // restablece todos los pixeles en apagado
  tira1.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled1; i++) { // bucle para recorrer posiciones 0 a 7
    tira1.setPixelColor(i, 255, 255, 0);   // cada pixel en color azul (posicion,R,G,B)
    tira1.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }
}

void cian() {
  sliderb.getValue(&valbrillo);
  brillo = (valbrillo * 1.5);
  tira.clear();       // restablece todos los pixeles en apagado
  tira.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled; i++) { // bucle para recorrer posiciones 0 a 7
    tira.setPixelColor(i, 0, 255, 255);   // cada pixel en color azul (posicion,R,G,B)
    tira.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }

  tira1.clear();       // restablece todos los pixeles en apagado
  tira1.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled1; i++) { // bucle para recorrer posiciones 0 a 7
    tira1.setPixelColor(i, 0, 255, 255);   // cada pixel en color azul (posicion,R,G,B)
    tira1.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }
}

void convelocidad() {
  slidervel.getValue(&valvel);
  if (valvel > 0) {
    for (int i = 0; valvel > 0 ; i++) {
      motor.setSpeed(valvel * 3);
      motor.step(100);
      slidervel.getValue(&valvel);
    }
  }
}

void coffvelocidad() {
  motor.setSpeed(90);
  motor.step(0);
}

void conluces() {
  sliderr.getValue(&valr);
  sliderv.getValue(&valv);
  slidera.getValue(&vala);
  sliderb.getValue(&valbrillo);
  brillo = (valbrillo * 1.5);
  tira.clear();       // restablece todos los pixeles en apagado
  tira.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled; i++) { // bucle para recorrer posiciones 0 a 7
    tira.setPixelColor(i, valr, valv, vala);   // cada pixel en color azul (posicion,R,G,B)
    tira.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }

  tira1.clear();       // restablece todos los pixeles en apagado
  tira1.setBrightness(brillo);       // brillo global para toda la tira
  for (int i = 0; i < numled1; i++) { // bucle para recorrer posiciones 0 a 7
    tira1.setPixelColor(i, valr, valv, vala);   // cada pixel en color azul (posicion,R,G,B)
    tira1.show();      // muestra datos en pixel
    delay(5);       // breve demora de medio segundo
  }

}

void blanco2() {
  sliderb2.getValue(&valbrillo2);
  brillo2 = round(valbrillo2*0.63 );
  PORTC=1; //ENVIA COLOR 
  delay(10);
  //while(1)
  
  PORTC=brillo2;
  
  delay(100);
  PORTC=0;
}

void off2() {
  PORTC=8; //ENVIA COLOR 
  delay(10);
}
void rojo2() {
  sliderb2.getValue(&valbrillo2);
  brillo2 = round(valbrillo2*0.63 );
  PORTC=2; //ENVIA COLOR 
  delay(10);
  //while(1)
  
  PORTC=brillo2;
  
  delay(100);
  PORTC=0;
}
void verde2() {
    sliderb2.getValue(&valbrillo2);
  brillo2 = round(valbrillo2*0.63 );
  PORTC=3; //ENVIA COLOR 
  delay(10);
  //while(1)
  
  PORTC=brillo2;
  
  delay(100);
  PORTC=0;
}
void azul2() {
  sliderb2.getValue(&valbrillo2);
  brillo2 = round(valbrillo2*0.63 );
  PORTC=4; //ENVIA COLOR 
  delay(10);
  //while(1)
  
  PORTC=brillo2;
  
  delay(100);
  PORTC=0;
}

void magenta2() {
  sliderb2.getValue(&valbrillo2);
  brillo2 = round(valbrillo2*0.63 );
  PORTC=5; //ENVIA COLOR 
  delay(10);
  //while(1)
  
  PORTC=brillo2;
  
  delay(100);
  PORTC=0;
}

void amarillo2() {
    sliderb2.getValue(&valbrillo2);
  brillo2 = round(valbrillo2*0.63 );
  PORTC=6; //ENVIA COLOR 
  delay(10);
  //while(1)
  
  PORTC=brillo2;
  
  delay(100);
  PORTC=0;
}
void cian2() {
  sliderb2.getValue(&valbrillo2);
  brillo2 = round(valbrillo2*0.63 );
  PORTC=7 ; //ENVIA COLOR 
  delay(10);
  
  PORTC=brillo2;
  
  delay(100);
  PORTC=0;
}
void conluces2() {
  sliderr2.getValue(&valr2);
  sliderv2.getValue(&valv2);
  slidera2.getValue(&vala2);
  sliderb2.getValue(&valbrillo2);
  brillo2 = round(valbrillo2*0.63 );
  valr2=round(valr2/4);
  valv2=round(valv2/4);
  vala2=round(vala2/4);
  PORTC=9; //METODO COMBINACION DE LUCES
  delay(10);
  PORTC=brillo2;
  delay(50);
  PORTC=valr2;
  delay(50);
  PORTC=valv2;
  delay(50);
  PORTC=vala2;
  delay(100);
  PORTC=0;  
}

void setup() {
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  DDRC=255;
  PORTC=0;
  
 // nexInit();
  tira.begin();       // inicializacion de la tira
  tira.show();        // muestra datos en pixel
  tira1.begin();       // inicializacion de la tira
  tira1.show();        // muestra datos en pixel
  bpos.attachPop(posicion);
  btn1.attachPop(opc1);
  btn2.attachPop(opc2);
  btn3.attachPop(opc3);
  bon.attachPop(on);
  boff.attachPop(off);
  btnr.attachPop(rojo);
  btnv.attachPop(verde);
  btna.attachPop(azul);
  btnm.attachPop(magenta);
  btnam.attachPop(amarillo);
  btnc.attachPop(cian);
  btnon1.attachPop(convelocidad);
  btnoff1.attachPop(coffvelocidad);
  btnon2.attachPop(conluces);
  btnoff2.attachPop(off);
  bon3.attachPop(conluces2);
  boff3.attachPop(off2);
  btnb2.attachPop(blanco2);
  btnr2.attachPop(rojo2);
  btnv2.attachPop(verde2);
  btna2.attachPop(azul2);
  btnm2.attachPop(magenta2);
  btnam2.attachPop(amarillo2);
  btnc2.attachPop(cian2);


}

void loop() {
  nexLoop(nex_listen_list);
}
