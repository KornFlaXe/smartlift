/*  Gestion pages et boutons des menus  */

// FONCTION BARRE D'ETAT (BANDEROLE)
void  StatusBar()  {

  /*  Horizontal, Vertical, Width, Height, Color  */
  tft.fillRect(0, 0, 480, 40, StatusBarColor);             //  Arrière-plan Barre d'Etat
  /*tft.drawRect(0, 0, 480, 320, StatusBarColor);            //  Bordure Plein Ecran


  /*  Si la page actuelle n'est pas le Menu  */
  if  (CurrentPage != "LiftOS") {
    /*  AFFICHER L'ICONE RETOUR  */
    drawHomeIcon();
  }

  /*  SI il y'a un menu Info pour la page, affiche "i" en haut à droite de la barre d'état  */
  if  (MenuInfo ==  1)  {    
   tft.setTextSize(3);
   tft.setTextColor(TextColor);
   tft.setCursor(450, 10);
   tft.println("i");
  }
  
  /*  -------------------------------------------------------------------------------------------------------  */
  /*  COULEUR TEXTE EN FONCTION DE LA COULEUR DE LA BARRE D'ETAT  */
  tft.setTextSize(3);
  if  (StatusBarColor != WHITE && StatusBarColor != YELLOW)  { //  Si BARRE D'ETAT n'est pas BLANCHE, ni JAUNE
    tft.setTextColor(WHITE);                      //  Mettre la couleur du texte en BLANC
  }
  else  {
    tft.setTextColor(BLACK);                      //  Sinon mettre la couleur du texte en NOIR
  }

  /*  -------------------------------------------------------------------------------------------------------  */
  /*  CENTRER LE TEXTE DE LA BARRE D'ETAT */
  if (CurrentPage == "LiftOS") {
    tft.setCursor(20, 20);                        //  Horizontal, Vertical position
    tft.setTextSize(2);
  }
    else if (CurrentPage == "Test Moteur") {
    tft.setTextColor(BLACK);
    tft.setCursor(160, 10);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Test Alerte") {
    tft.setCursor(160, 10);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Test Buzzer") {
    tft.setCursor(160, 10);                       //  Horizontal, Vertical position
  }
  else if (CurrentPage == "Credits") {
    tft.setCursor(190, 10);                       //  Horizontal, Vertical position
  }
  else  {
    tft.setCursor(200, 10);                       //  Horizontal, Vertical position
  }

  tft.print(CurrentPage);

  /*  -------------------------------------------------------------------------------------------------------  */
  /*  Rafraichir l'ecran en fonction du type de page  */
  if ((PrevPage == "Test Moteur") || (PrevPage == "Test Alerte") || (PrevPage == "Test Buzzer") || (PrevPage == "Credits")) {
    ClearPage();                      //  Clear Page
  }
  if ((PrevPage == "Info") || (PrevPage == "LiftOS")) {
    ClearFullPage();
  }  
  else {
    ClearButtons();                   //  Clear Buttons
  }
}

/*  -------------------------------------------------------------------------------------------------------  */

void BottomBar() {
  tft.fillRect(0, 240, 480, 60, BottomBarColor);
  tft.setTextSize(2);
  tft.setTextColor(TextColor);
  tft.setCursor(310, 20);
  tft.println("Firmware 1.0b");
  tft.setCursor(20, 262);
  tft.println("Systeme SmartLift operationnel");
}

/*  ----------------------------------------------------------------------------------------------------------  */
void  drawHomeMenu()  {           //  Menu Principal contenant les 4 buttons

  tft.setTextSize(2);
  tft.setTextColor(TextColor);

  /*  Button 1 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 55, 210, 70, BtnBorderColor);   //
  tft.drawRect(21, 56, 208, 68, BtnBorderColor);
  tft.setCursor(60, 83);
  tft.println("TEST MOTEUR");

  /*  Button 2 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 55, 210, 70, BtnBorderColor);
  tft.drawRect(251, 56, 208, 68, BtnBorderColor);
  tft.setCursor(290, 83);
  tft.println("TEST ALERTE");

  /*  Button 3 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(20, 145, 210, 70, BtnBorderColor);
  tft.drawRect(21, 146, 208, 68, BtnBorderColor);
  tft.setCursor(60, 173);
  tft.println("TEST BUZZER");

  /*  Button 4 - Horizontal, Vertical, Width, Height, Color  */
  tft.drawRect(250, 145, 210, 70, BtnBorderColor);
  tft.drawRect(251, 146, 208, 68, BtnBorderColor);
  tft.setCursor(312, 173);
  tft.println("CREDITS");

}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawMotorMenu()  {          // Menu pour tester le moteur
  /*  DATE  */
  tft.setCursor(115, 60);
  tft.setTextSize(3);
  tft.setTextColor(GREY);
  tft.println("ETAGE ACTUEL");

  /*  TIME  */
  tft.setTextSize(9);
  tft.setTextColor(WHITE);
  tft.setCursor(115, 130);
  tft.print(input);
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawCreditsMenu()  {         /*  Menu des credits  */

  tft.setCursor(140, 60);
  tft.setTextSize(3);
  tft.setTextColor(SKY);
  OSVersion();

  tft.setTextSize(3);
  tft.setTextColor(GREY);
  tft.setCursor(170, 105);
  tft.println("CREDITS:");

  tft.setTextSize(2);
  tft.setTextColor(SALMON);
  tft.setCursor(70, 150);
  tft.print("Developpe par:  ");
  tft.setTextColor(WHITE);
  tft.print("Ludovic / Wael");
  tft.setTextColor(SKY);
  tft.setCursor(165, 190);
  tft.print("www.efrei.fr");

  tft.setTextColor(SALMON);
  tft.setCursor(70, 230);
  tft.print("Developpe pour: ");
  tft.setTextColor(WHITE);
  tft.print("Prj. SmartLift");
  tft.setTextColor(SKY);
  tft.setCursor(175, 270);
  tft.print("github.com");

}


/*  ----------------------------------------------------------------------------------------------------------  */
void  drawBuzzMenu()  {           //  Menu pour tester le Buzzer

  tft.setCursor(100, 60);
  tft.setTextSize(3);
  tft.setTextColor(GREY);
  tft.println("PRESSER UN BOUTON");
}

/*  ----------------------------------------------------------------------------------------------------------  */
void  drawAlertMenu()  {           /*  Menu pour tester et envoyer une alerte  */

  tft.setCursor(100, 60);
  tft.setTextSize(3);
  tft.setTextColor(GREY);
  tft.println("PRESSER UN BOUTON");
}

/*  ----------------------------------------------------------------------------------------------------------  */
void  drawHomeIcon() {              /*  ICONE DE RETOUR  */

  tft.setTextSize(3);
  tft.setTextColor(TextColor);
  tft.setCursor(20, 10);
  tft.println("<");
}

/*  ----------------------------------------------------------------------------------------------------------  */
void  ClearPage() {                       //  Fonction pour rafraichir les menus et la barre d'etat

  tft.fillRect(20, 55, 440, 250, BLACK);                        //  Clear Menu
}

/*  ----------------------------------------------------------------------------------------------------------  */
void  ClearButtons()  {                   //  Fonction pour rafraichir le texte et les boutons

  tft.fillRect(20, 55, 210, 70, BLACK);                       //  Button 1 FULL
  tft.fillRect(250, 55, 210, 70, BLACK);                      //  Button 2 FULL
  tft.fillRect(20, 145, 210, 70, BLACK);                      //  Button 3 FULL
  tft.fillRect(250, 145, 210, 70, BLACK);                     //  Button 4 FULL
}

/*  ----------------------------------------------------------------------------------------------------------  */
void  ClearFullPage()  {                     /*  Rafraichi le texte des boutons  */

  tft.fillRect(0, 40, 480, 320, BLACK);  //  Clear full page
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  SaveToEEPROM()  {         /*  Save these values to the EEPROM, so it will not lose settings without power  */
/*
  if  (CurrentPage == "Led Options") {
    delay(500);                   //  short delay to prevent saving twice with one single press of the button
    EEPROM.write(1, blv);         //  Save Led Brightness value to EEPROM
    EEPROM.write(2, esleep);      //  Save the LedTimer value to EEPROM
    Serial.println(F("*****  SAVED LED OPTIONS TO EEPROM  *****"));
  }
  else  {
    //  Serial.println("*****  SAVED TO EEPROM  *****");
  }*/
}

/*  ----------------------------------------------------------------------------------------------------------  */

void  drawInfoPage()  {                   /*  Pages Information  */

//  tft.drawLine(20, 0, 20, 320, YELLOW);     //  Left Line border (only for aligning the text)
//  tft.drawLine(460, 0, 460, 320, YELLOW);   //  Right Line border (only for aligning the text)
  
  tft.setTextSize(2);
  tft.setTextColor(TextColor);

  if  (PrevPage == "Test Alerte")  {                         //  Page Info du Menu Alerte
    tft.setCursor(20, 80);
    tft.print("Vous pouvez utiliser ce programme");
    tft.setCursor(20, 110);
    tft.print("pour envoyer une alerte.");
    tft.setCursor(20, 140);
    tft.print("Pour cela, pressez un des");
    tft.setCursor(20, 170);
    tft.print("boutons sur le circuit.");
    tft.setCursor(20, 200);
    tft.print("N'oubliez pas d'ouvrir l'appli");
    tft.setCursor(20, 230);
    tft.print("pour recevoir la notification.");
    tft.setCursor(20, 260);
    tft.print("");
  }

  if  (PrevPage == "Test Buzzer")  {                         //  Page Info du Menu Buzzer
    tft.setCursor(20, 80);
    tft.print("Vous pouvez utiliser ce programme");
    tft.setCursor(20, 110);
    tft.print("pour tester le buzzer.");
    tft.setCursor(20, 140);
    tft.print("Pour cela, pressez un des");
    tft.setCursor(20, 170);
    tft.print("boutons sur le circuit.");
    tft.setCursor(20, 200);
    tft.print("Attention : le son emis peut etre");
    tft.setCursor(20, 230);
    tft.print("tres fort.");
    tft.setCursor(20, 260);
    tft.print("");
  } 
}

/*  ----------------------------------------------------------------------------------------------------------  */

unsigned long displayErr1() {                       /* Affichages des erreurs en fonction du type de panne  */
  tft.fillRect(0, 140, 480, 200, BLACK);
  tft.setCursor(20, 140);
  tft.setTextColor(RED); tft.setTextSize(2);
  tft.print("ERR1 : Une erreur est survenue :(");
  tft.setCursor(20, 170);
  tft.setTextColor(WHITE);
  tft.print("Veuillez contacter l'ascensoriste.");
}

unsigned long displayErr2() {
  tft.fillRect(0, 140, 480, 200, BLACK);
  tft.setCursor(20, 140);
  tft.setTextColor(RED); tft.setTextSize(2);
  tft.print("ERR2 : L'ascenseur est bloque :(");
  tft.setCursor(20, 170);
  tft.setTextColor(WHITE);
  tft.print("Essayer de redemarrer,sinon contacter");
  tft.setCursor(20, 200);
  tft.print("l'ascensoriste.");
}

unsigned long displayErr3() {
  tft.fillRect(0, 140, 480, 200, BLACK);
  tft.setCursor(20, 140);
  tft.setTextColor(RED); tft.setTextSize(2);
  tft.print("ERR3 : L'ascenseur est en surcharge !");
  tft.setCursor(20, 170);
  tft.setTextColor(WHITE);
  tft.print("Veuillez respecter le poids maximal");
  tft.setCursor(20, 200);
  tft.print("supporte par la cage.");
}

/*  ----------------------------------------------------------------------------------------------------------  */

void moveUp() {                                     /*  Code concernant le mouvement du moteur  */
  digitalWrite(dirPin, HIGH);
  for(int i = 0; i < (1.8*stepsPerRevolution*floorDiff)+compensation; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  Beep();
}

void moveDown() {
  digitalWrite(dirPin, LOW);
  for(int i = 0; i < (1.8*stepsPerRevolution*floorDiff)-compensation; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  Beep();
}

/*  ----------------------------------------------------------------------------------------------------------  */

unsigned long displayMoving() {
  
  tft.fillRect(0, 240, 480, 60, BottomBarColor);
  tft.setTextSize(2);
  tft.setTextColor(TextColor);
  tft.setCursor(20, 262);
  tft.print("L'ascenseur ");
  if (lastInput < input) {
    tft.print((char)24);
  }
  else if (lastInput > input) {
    tft.print((char)25);
  }
  tft.print(" de l'etage ");
  tft.print(lastInput);
  tft.print(" vers ");
  tft.print(input);
}

/*  ----------------------------------------------------------------------------------------------------------  */

unsigned long displayFloor() {

  if(CurrentPage == "LiftOS") {
    tft.fillRect(0, 240, 480, 60, BottomBarColor);
    tft.setTextSize(2);
    tft.setTextColor(TextColor);
    tft.setCursor(20, 262);
    tft.print("Position de l'ascenseur : ");
    tft.print(" Etage ");
    tft.print(input);
  }
}

/*  ----------------------------------------------------------------------------------------------------------  */


void serialEvent() {                               /*  Gestion des évènements au sein du programme  */
  while (Serial2.available()) {
    input = Serial2.read();
    displayMoving();
    stringComplete = true;
  }
}
