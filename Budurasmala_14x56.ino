// GK Technologies
// Program by Gimhana Wedage


#define FASTLED_ALLOW_INTERRUPTS 0 //This line should be added if you are using the NodeMCU Board
#include "FastLED.h"
#include <ESP8266WiFi.h>


typedef enum {
  Up,
  Down,
  Left,
  Right,
  LeftUp,
  LeftDown,
  RightUp,
  RightDown
} 
Direction;

typedef enum {
  Inside,
  Outside
}
DataInput;


#define LED_Rows 14 //Number of LED Rows (Maximum 8).
#define LED_Columns 56 //Number of LED Columns (Maximum 25).
#define NUM_LEDS LED_Rows * LED_Columns //Total Number of LEDs

#define Data_Input Inside // Inside or Outside
#define DATA_IN_OFFSET 7 // Data Input point offset

#define DATA_PIN 7
#define BRIGHTNESS  180

CRGB leds[NUM_LEDS];




int DELAY;

//void Animate(Direction direc, int sp, int steps=0);

                                      
void setup() {
  delay(500);
  FastLED.setBrightness( BRIGHTNESS );
  DELAY = 40; //Increase this value to slow down the patterns
  
  // Uncomment one of the following lines for your leds arrangement.
  //FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  // FastLED.setBrightness(CRGB(255,255,255));
  // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);

   Serial.begin(74880);
   delay(500);
 
   Serial.println();
   Serial.println(WiFi.macAddress());

   //2171 : EC:FA:BC:C1:EB:17 (Inside, Offset 7, SMD)       Kirulapona
   //2106 : EC:FA:BC:C1:EC:70 (Inside, Offset 8, 12mm old)  Kadawata
   //2178 : EC:FA:BC:C1:E8:3B (Inside, Offset 7 SMD)        Nittambuwa
   //2187 : EC:FA:BC:C1:F6:88 (Inside, Offset 7 SMD)        Halpita
   //2188 : EC:FA:BC:C1:F8:17 (Inside, Offset 7 SMD)        Talawakele
   //2189 : 50:02:91:68:0E:9F (Inside, Offset 7, 12mm)      Ambalangoda 
   //2104 : 48:3F:DA:9D:E5:85 (Inside, Offset 8, 12mm old, Bright 160) Matara
   //2213 : 48:3F:DA:9D:D4:18 (Inside, Offset 7 SMD) 

    
}

void loop() 
{

    if (WiFi.macAddress() != "48:3F:DA:9D:D4:18") 
       return;

    Run_BFlagDiagonal();
    Run_RainbowLotus();
    Run_RedPieces();
    
    Run_Circles1();
    Run_RNBChess();
    Run_ZigZagBlue();
    Run_DharmaChakra();
    Run_BlueLotus(20, DELAY);
    Run_Chess();
    Run_BFLotus(5, DELAY);
    Run_YR_Spiral_2L();
    Run_RainbowButterfly();
    Run_MalWedi();
    Run_DL_RY(); // in DL_Rotate1
    Run_Flower1();
    Run_DL_Rotate2_Bounce();
    Run_DL_Rotate2();
    Run_DL_Rotate2_2();
    Run_DL_Rotate3();
    Run_DL_Rotate1();
  
    Run_BYR_Spiral();
    Run_BYR_Rotate();
    Run_ZigZagRed();
    
}


























 
