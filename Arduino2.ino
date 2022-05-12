#include <Adafruit_NeoPixel.h>    // importa libreria
#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial 
int tipo=0; //tipo de trama, primer bit recibido por serial
int brillo=0;
int r=0;
int g=0;
int b=0;

Adafruit_NeoPixel tira = Adafruit_NeoPixel(120, 10, NEO_GRB + NEO_KHZ800); // creacion de objeto "tira"

void setup() {
  Serial.begin(9600);
tira.begin();       // inicializacion de la tira
tira.show(); 
DDRC=0; //PUERTO C ENTRADAS
}

void loop() {

 if (PINC==1) //evalua bit1
 {
  Serial.println(PINC);
  delay(25);
  
  brillo=(PINC/0.63);
    Serial.println(brillo);
    delay(100);
      tira.clear();       
      tira.setBrightness(brillo); 
      for (int i = 0; i < 120; i++) 
       { // bucle para recorrer posiciones 0 a 7
          tira.setPixelColor(i, 255, 255, 255);   // cada pixel en color azul (posicion,R,G,B)
          tira.show();      // muestra datos en pixel
          delay(5);       // breve demora de medio segundo
       }    
 }
 else if (PINC==2) // ROJOOO
 {
  Serial.println(PINC);
  delay(25);
  
  brillo=(PINC/0.63);
    Serial.println(brillo);
    delay(100);
      tira.clear();       
      tira.setBrightness(brillo); 
      for (int i = 0; i < 120; i++) 
       { // bucle para recorrer posiciones 0 a 7
          tira.setPixelColor(i, 255, 0, 0);   // cada pixel en color azul (posicion,R,G,B)
          tira.show();      // muestra datos en pixel
          delay(5);       // breve demora de medio segundo
       }    
 }

else if (PINC==3) // VERDE
 {
  Serial.println(PINC);
  delay(25);
  
  brillo=(PINC/0.63);
    Serial.println(brillo);
    delay(100);
      tira.clear();       
      tira.setBrightness(brillo); 
      for (int i = 0; i < 120; i++) 
       { // bucle para recorrer posiciones 0 a 7
          tira.setPixelColor(i, 0, 255, 0);   // cada pixel en color azul (posicion,R,G,B)
          tira.show();      // muestra datos en pixel
          delay(5);       // breve demora de medio segundo
       }    
 }

 else if (PINC==4) // AZUL
 {
  Serial.println(PINC);
  delay(25);
  
  brillo=(PINC/0.63);
    Serial.println(brillo);
    delay(100);
      tira.clear();       
      tira.setBrightness(brillo); 
      for (int i = 0; i < 120; i++) 
       { // bucle para recorrer posiciones 0 a 7
          tira.setPixelColor(i, 0, 0, 255);   // cada pixel en color azul (posicion,R,G,B)
          tira.show();      // muestra datos en pixel
          delay(5);       // breve demora de medio segundo
       }    
 }

 else if (PINC==5) // MAGENTA
 {
  Serial.println(PINC);
  delay(25);
  
  brillo=(PINC/0.63);
    Serial.println(brillo);
    delay(100);
      tira.clear();       
      tira.setBrightness(brillo); 
      for (int i = 0; i < 120; i++) 
       { // bucle para recorrer posiciones 0 a 7
          tira.setPixelColor(i, 255, 0, 128);   // cada pixel en color azul (posicion,R,G,B)
          tira.show();      // muestra datos en pixel
          delay(5);       // breve demora de medio segundo
       }    
 }

  else if (PINC==6) // AMARILLO
 {
  Serial.println(PINC);
  delay(25);
  
  brillo=(PINC/0.63);
    Serial.println(brillo);
    delay(100);
      tira.clear();       
      tira.setBrightness(brillo); 
      for (int i = 0; i < 120; i++) 
       { // bucle para recorrer posiciones 0 a 7
          tira.setPixelColor(i, 255, 255, 0);   // cada pixel en color azul (posicion,R,G,B)
          tira.show();      // muestra datos en pixel
          delay(5);       // breve demora de medio segundo
       }    
 }

 else if (PINC==7) // CIAN
 {
  Serial.println(PINC);
  delay(25);
  
  brillo=(PINC/0.63);
    Serial.println(brillo);
    delay(100);
      tira.clear();       
      tira.setBrightness(brillo); 
      for (int i = 0; i < 120; i++) 
       { // bucle para recorrer posiciones 0 a 7
          tira.setPixelColor(i, 0, 255, 255);   // cada pixel en color azul (posicion,R,G,B)
          tira.show();      // muestra datos en pixel
          delay(5);       // breve demora de medio segundo
       }    
 }

 else if (PINC==8) // APAGADO
 {
  tira.clear();
  tira.show(); 
 }
  else if (PINC==9) // COMBINACIÓN
 {
  Serial.println(PINC);
  delay(25);
  
  brillo=(PINC/0.63);
    Serial.println(brillo);
    delay(55);
    r=PINC*4+1;
    delay(55);
    g=PINC*4+1;
    delay(55);
    b=PINC*4+1;
      tira.clear();       
      tira.setBrightness(brillo); 
      for (int i = 0; i < 120; i++) 
       { // bucle para recorrer posiciones 0 a 7
          tira.setPixelColor(i, r, g, b);   // cada pixel en color azul (posicion,R,G,B)
          tira.show();      // muestra datos en pixel
          delay(5);       // breve demora de medio segundo
       }    
 }
}
