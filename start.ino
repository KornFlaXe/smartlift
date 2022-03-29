/* Affiche la version de l'OS et l'ecran de démarrage */

void OSVersion()  {
  tft.println(LiftOS_version);
}

/* ECRAN DE DEMARRAGE */

void StartupScreen()   {

#define wait1 70
#define wait2 50

  /*  Horizontal, Vertical, Width, Height  */

  /*tft.drawRect(0, 0, 480, 320, WHITE);*/
  tft.drawRect(20, 70, 440, 150, WHITE);
  delay(wait1);
  tft.fillRect(40, 90, 50, 100, DarkMAGENTA);
  delay(wait1);
  tft.fillRect(110, 90, 50, 100, DarkMAGENTA);
  delay(wait1);
  tft.fillRect(180, 90, 50, 100, DarkMAGENTA);
  delay(wait1);
  tft.fillRect(250, 90, 50, 100, DarkMAGENTA);    //
  delay(wait1);
  tft.fillRect(320, 90, 50, 100, BLUE);  //
  delay(wait1);
  tft.fillRect(390, 90, 50, 100, BLUE);  //

  delay(150);

  tft.setTextSize(5);
  tft.setTextColor(WHITE);

  /*  Horizontal, Vertical  */
  tft.setCursor(52, 120);
  tft.print("L");
  delay(wait2);
  tft.setCursor(122, 120);
  tft.print("I");
  delay(wait2);
  tft.setCursor(192, 120);
  tft.print("F");
  delay(wait2);
  tft.setCursor(262, 120);
  tft.print("T");
  delay(wait2);
  tft.setCursor(332, 120);
  tft.print("O");
  delay(wait2);
  tft.setCursor(402, 120);
  tft.print("S");
  delay(wait2);

  delay(700);

  tft.setTextSize(2);
  tft.setCursor(105, 230);
  tft.print("Version modifiee MarcOS");
  tft.setCursor(175, 260);
  tft.setTextSize(1);
  tft.print("EFREI PARIS - 2022");
}
