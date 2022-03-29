/* Partie Setup */

#include "NewToneLib.h"
#include <SPI.h>
#define BUZ_PIN 10

MyTone t(false);

void setup(void) {

  Serial.begin(9600);
  Serial.println("Le port serie demarre");

  Serial2.begin(9600);
  Serial.println("Le port bluetooth demarre");

  tft.reset();
  tft.begin(0x9486);
  tft.setRotation(LCDROTATION);
  tft.fillScreen(BLACK);

  StartupScreen();

  pinMode(BUZ_PIN, OUTPUT);       // Pin BUZZER déclaré comme SORTIE
  pinMode(stepPin, OUTPUT);       // Pin MOTEUR (step) déclaré comme SORTIE
  pinMode(dirPin, OUTPUT);        // Pin MOTEUR (dir) déclaré comme SORTIE
  pinMode(A8,INPUT_PULLUP);
  pinMode(A9,INPUT_PULLUP);
  pinMode(A10,INPUT_PULLUP);
  
  //Melody();
  
  delay(1500);

  ClearPage();
  HomeScreen();

  Serial.println("Demarrage de la boucle");
  Serial2.println("Le systeme SmartLift a demarre");
}

void Melody() {
  t.tone(BUZ_PIN, 523, 300);//pin, frequency(Hz), duration(ms)
  t.tone(BUZ_PIN, 698, 300);
  t.tone(BUZ_PIN, 784, 300);
  t.tone(BUZ_PIN, 880, 500);
  //t.tone(BUZ_PIN, 1976, 600);
  delay(500);
}

void Beep() {
  t.tone(BUZ_PIN, 1480, 400);
}
