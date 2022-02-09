////////////////////////////////////////////////////////////
#include <SD.h>  
#include <SPI.h>
#include <TMRpcm.h>  
#define pinSD 10     //define el pin para seleccionar la tarjeta SD
TMRpcm tmrpcm;   //Se crea un objeto de la librería TMRpcm
const int BUTTON_PIN_7 = 7;  
const int BUTTON_PIN_6 = 6;  
const int BUTTON_PIN_5 = 5;  
const int BUTTON_PIN_4 = 4;  


void setup(){
  tmrpcm.speakerPin = 9; // define el pin en el que está conectado el parlante
  Serial.begin(9600);    

  if (!SD.begin(pinSD)) {  // verifica la coneccion de la tarjeta sd:
    Serial.println("Fallo en la tarjeta SD");  //Aviso de que algo no anda bien 
    return;   //No hacer nada si no se pudo leer la tarjeta
  }

    pinMode(BUTTON_PIN_7, INPUT_PULLUP);
    pinMode(BUTTON_PIN_6, INPUT_PULLUP);
    pinMode(BUTTON_PIN_5, INPUT_PULLUP);
    pinMode(BUTTON_PIN_4, INPUT_PULLUP);

}

void loop(){  
     if ( digitalRead(BUTTON_PIN_7)  == false ){
           Serial.println("pad1");  
           tmrpcm.play("hhat.wav");
          }

     if ( digitalRead(BUTTON_PIN_6)  == false ){
           Serial.println("pad2");  
           tmrpcm.play("plati1.wav");    
          }

     if ( digitalRead(BUTTON_PIN_5)  == false ){
          Serial.println("pad3"); 
          tmrpcm.play("plati2.wav");      
          }

     if (digitalRead(BUTTON_PIN_4)  == false ){
          Serial.println("pad4");  
          tmrpcm.play("bombo1.wav");    
          }
  }
  
  
