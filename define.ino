/* Librairies et variables */

// Librairies ILI9486
#include <MCUFRIEND_kbv.h>
#include <Adafruit_GFX.h>
#include <TouchScreen.h>

// Port Communication Bluetooth
#define BTSerial Serial2;

// Assigner des noms aux pins utilisés de la carte ARDUINO
#define LCD_CS A3     // Pin LCD Chip Select  ANALOG 3
#define LCD_CD A2     // Pin LCD Command Data ANALOG 2
#define LCD_WR A1     // Pin LCD Write        ANALOG 1
#define LCD_RD A0     // Pin LCD Read         ANALOG 0
#define LCD_RESET A4  // Pin LCD Reset        ANALOG 4
#define LCDROTATION 3 // Rotation Ecran

// Coordonnées Ecran Tactile
#define YP A3
#define XM A2
#define YM 9
#define XP 8

#define TS_MINX 827
#define TS_MINY 162
#define TS_MAXX 136
#define TS_MAXY 931

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// Valeurs pression ecran
#define MINPRESSURE 10     // Valeur Pression Minimum
#define MAXPRESSURE 1000   // Valeur Pression Maximum

// Pins et paramètres du Moteur
#define dirPin 12
#define stepPin 13
#define stepsPerRevolution 800

// Couleurs Hexadecimal
#define BLACK           0x0000
#define WHITE           0xFFFF
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x2685
#define CYAN            0x07FF
#define LIME            0x5FE0
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define TURQUOISE       0x0F1B
#define ORANGE          0xFBA0
#define PINK            0xF813
#define SKY             0x667F
#define GREY            0xE73C
#define DarkTURQUOISE   0x3491
#define DarkGREY        0x39C7
#define DarkRED         0x8986
#define DarkGREEN       0x3446
#define DarkMAGENTA     0x612F
#define DarkBLUE        0x298B
#define DarkYELLOW      0x83E5
#define DarkORANGE      0xA347
#define DarkPINK        0xA1EF
#define GOLD            0xF3FF00
#define SALMON          0xFB2C

/* Variables Menu */
String CurrentPage;
String PrevPage;
int btn0Val            =  0;          //  Valeur par défaut Bouton 1
int btn1Val            =  0;          //  Valeur par défaut Bouton 2
int btn2Val            =  0;          //  Valeur par défaut Bouton 3
int StatusBarColor     =  SKY;        //  Couleur par défaut Barre d'Etat
int BottomBarColor     =  GREEN;      //  Couleur par défaut Barre
int TextColor          =  WHITE;      //  Couleur par défaut Texte
int MenuInfo           =  0;          //  0 = OFF, 1 = ON
int MenuColor;
int BtnBorderColor;

int input;
int lastInput;
int floorDiff;
int compensation;
bool stringComplete = false;

/* Initialiser l'ecran */
MCUFRIEND_kbv tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
