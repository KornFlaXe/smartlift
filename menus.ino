/* Fonctions des Menus */

void  HomeScreen()  {

  CurrentPage     =  "LiftOS";
  MenuInfo        =   0;
  StatusBarColor  =   SKY;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  BottomBarColor  =   GREEN;
  StatusBar();
  BottomBar();
  drawHomeMenu();
  PrevPage        =   CurrentPage;
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  TestMotor()  {

  CurrentPage     =   "Test Moteur";
  MenuInfo        =   0;
  StatusBarColor  =   BLACK;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();
  drawMotorMenu();
  PrevPage        =   CurrentPage;
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  TestAlert()  {

  CurrentPage     =   "Test Alerte";
  MenuInfo        =   1;
  StatusBarColor  =   RED;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   WHITE;
  StatusBar();
  drawAlertMenu();
  PrevPage        =   CurrentPage;
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  TestBuzzer()  {

  CurrentPage     =   "Test Buzzer";
  MenuInfo        =   1;
  StatusBarColor  =   ORANGE;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   WHITE;
  StatusBar();
  drawBuzzMenu();
  PrevPage        =   CurrentPage;
}

/*  ----------------------------------------------------------------------------------------------------------  */
void  CreditsMenu()  {

  CurrentPage     =   "Credits";
  MenuInfo        =   0;
  StatusBarColor  =   GREY;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  StatusBar();
  drawCreditsMenu();
  PrevPage        =   CurrentPage;
}


/*  ----------------------------------------------------------------------------------------------------------  */
void  InfoPage() {

  CurrentPage     =  "Info";
  MenuInfo        =   0;
  StatusBarColor  =   GREEN;
  MenuColor       =   StatusBarColor;
  TextColor       =   TextColor;
  BtnBorderColor  =   MenuColor;
  StatusBar();
  drawInfoPage();
  PrevPage        =   CurrentPage;

}
