/* Definir les Boutons et leurs fonction */

void Touch() {

  TSPoint p = ts.getPoint();

  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {

    // scale from 0->1023 to tft.width
    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
    p.y = map(p.y, TS_MINY, TS_MAXY, tft.height(), 0);

    /*  Display Touch coordinates and pressure to the Serial console  */
    Serial.print("p.x = ");
    Serial.print(p.x);
    Serial.print("  |  p.y = ");
    Serial.print(p.y);
    Serial.print("  |  Pression = ");
    Serial.println(p.z);

  /*  -------------------------------------------------------------------------------------------------------  */    
    if  (CurrentPage != "LiftOS") {                           //  if not in home menu display home button
      //  Top-Left corner of the Status Bar  - RIGHT  &  EDGE & TOP  & BOTTOM EDGE
      if (p.y > 310 && p.y < 339 && p.x > 0 && p.x < 60) {
        HomeScreen();   //  Go Back to Home Screen
      }
    }

    //  Button 1  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
    if (p.y > 183 && p.y < 328 && p.x > 88 && p.x < 192) {

      /*  These must be defined in reverse order to work */
      if  (CurrentPage == "Menu4") {
      }
      else if  (CurrentPage == "Menu3") {
      }
      else if  (CurrentPage == "Menu2") {
      }
      else if  (CurrentPage == "Menu1") {
      }
      else if  (CurrentPage == "LiftOS") {
        TestMotor();
      }
    }

    //  Button 2  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
    else if (p.y > 22 && p.y < 164 && p.x > 88 && p.x < 192) {

      /*  These must be defined in reverse order for it to work */
      if  (CurrentPage == "Menu4") {
      }
      else if  (CurrentPage == "Menu3") {
      }
      else if  (CurrentPage == "Menu2") {
      }
      else if  (CurrentPage == "Menu1") {
      }
      else if  (CurrentPage == "LiftOS") {
        TestAlert();
      }
    }

    //    Button 3  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
    if (p.y > 183 && p.y < 328 && p.x > 227 && p.x < 334) {

      /*  These must be defined in reverse order for it to work */
      if  (CurrentPage == "Menu4") {
      }
      else if  (CurrentPage == "Menu3") {
      }
      else if  (CurrentPage == "Menu2") {
      }
      else if  (CurrentPage == "Menu1") {
      }
      else if  (CurrentPage == "LiftOS") {
        TestBuzzer();
      }
    }

    //  Button 4  - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE
    if (p.y > 22 && p.y < 164 && p.x > 227 && p.x < 334) {

      /*  These must be defined in reverse order for it to work */
      if  (CurrentPage == "Menu4") {
      }
      else if  (CurrentPage == "Menu3") {
      }
      else if  (CurrentPage == "Menu2") {
      }
      else if  (CurrentPage == "Menu1") {
        HomeScreen();
      }
      else if  (CurrentPage == "LiftOS") {
        CreditsMenu();
      }
    }

    /*  BACK & SAVE BUTTONS BEGIN  */

    //  BACK Button - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  BACK TO PREVIOUS PAGE
    if (p.y > 189 && p.y < 260 && p.x > 426 && p.x < 469) {

      if  (CurrentPage == "LiftOS") {
      }
      else if  (CurrentPage == "Led Options") {
        //  Serial.println("Go back to Led Menu");
        TestAlert();
      }

//      else {
//        //      Do Nothing
//      }
    }

    //  SAVE Button - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE  -  SAVE TO EEPROM
    if (p.y > 90 && p.y < 159 && p.x > 426 && p.x < 469) {

      if  (CurrentPage == "Led Options") {
        SaveToEEPROM();
      }
    }

    /*  INFO AREA BEGIN*/

    //  Info area - RIGHT & LEFT EDGE & TOP & BOTTOM EDGE   -   show info menu
    if (p.y > 0 && p.y < 40 && p.x > 5 && p.x < 60) {

//      if  (CurrentPage == "Led Menu") {
      if  (MenuInfo == 0) {
        //  Serial.println("There's no menu for this page");        
      }
      if  (MenuInfo == 1) {
        InfoPage();
      }
    }

    /*  INFO AREA  END*/
    
  }  
}
