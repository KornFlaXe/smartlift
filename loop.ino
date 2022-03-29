/* Partie Boucle */

void loop(void) {
  Touch();
  serialEvent();

  btn0Val=analogRead(A8);
  btn1Val=analogRead(A9);
  btn2Val=analogRead(A10);

  if (CurrentPage == "Test Moteur") {

    if(btn0Val<200) // Si le bouton est enclenché
    {
      Serial.println("L'ascenseur descend");
      //Melody();
      delay(500);
    }
    
    if(btn1Val<200) // Si le bouton est enclenché
    {
      Serial.println("L'ascenseur s'arrete");
      //Melody();
      Serial2.println("Alerte INFO1 : Le moteur a ete stoppe !");
      delay(500);
    }

    if(btn2Val<200) // Si le bouton est enclenché
    {
      Serial.println("L'ascenseur monte");
      //Melody();
      delay(500);
    }
  }

  if (CurrentPage == "Test Alerte") {

    if(btn0Val<200) // Si le bouton est enclenché
    {
      Serial.println("Alerte panne de type ERR1");
      displayErr1();
      Serial2.println("Alerte ERR1 : Panne d'origine inconnue !");
      delay(500);
    }
    
    if(btn1Val<200) // Si le bouton est enclenché
    {
      Serial.println("Alerte panne de type ERR2");
      displayErr2();
      Serial2.println("Alerte ERR2 : L'ascenseur est bloque !");
      delay(500);
    }

    if(btn2Val<200) // Si le bouton est enclenché
    {
      Serial.println("Alerte panne de type ERR3");
      displayErr3();
      Serial2.println("Alerte ERR3 : L'ascenseur est en surcharge !");
      delay(500);
    }
  }

  if (CurrentPage == "Test Buzzer") {

    if(btn0Val<200) // Si le bouton est enclenché
    {
      Serial.println("bouton gauche enclenche menu buzzer");
      //Melody();
      delay(500);
    }
    
    if(btn1Val<200) // Si le bouton est enclenché
    {
      Serial.println("bouton milieu enclenche menu buzzer");
      Melody();
      delay(500);
    }

    if(btn2Val<200) // Si le bouton est enclenché
    {
      Serial.println("bouton droite enclenche menu buzzer");
      Beep();
      delay(500);
    }
  }

  if (stringComplete) {
    Serial2.print(lastInput);
    if (lastInput < input) {
      floorDiff = input - lastInput;
      moveUp();
    }
    else if (lastInput > input) {
      floorDiff = lastInput - input;
      moveDown();
    }
    displayFloor();
  }
  delay(100);
  lastInput = input;
  stringComplete = false;
}
