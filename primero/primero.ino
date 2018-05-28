//#include <SPI.h>  Not needed
//#include <Wire.h> Not needed
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "tiles.h"
#include "tilemap.h"

#define OLED_RESET 4 // not used 
Adafruit_SSD1306 display(OLED_RESET);
const int buttonPin = 16;
const int buttonPin2 = 14;
int buttonState = 0;         // variable for reading the pushbutton status
int button2State = 0;
int mapX = 0;
unsigned char currentTile[8];

void setup() {
  pinMode(13, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  pinMode(buttonPin2, INPUT);
  digitalWrite(buttonPin2, HIGH);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextColor(INVERSE);
  int TileMap;
  int ypos;
  Serial.begin(9600);
}

void loop() {

  display.clearDisplay();
  display.fillScreen(1);
  printArray(TileMap);
  buttonState = digitalRead(buttonPin);
  button2State = digitalRead(buttonPin2);

  if (buttonState == LOW) {
    mapX += 8;
  }
  if (button2State == LOW && mapX > 0) {
    mapX -= 8;
  }
  display.display();

}

void printArray( const int a[][ columns ] ) {
  // loop through array's rows
  for ( int i = 0; i < rows; ++i ) {
    // loop through columns of current row
    for ( int j = 0; j < columns; ++j ) {
      // c equals current cell value
      int c = a[i][j];
      if (c > 0) {
        int newc = c - 1;
        int target = newc * 8;
        //loop through tile array
        for ( int arrayindex = 0; arrayindex < 8; ++arrayindex ) {
          currentTile[arrayindex] = TileSet[target + arrayindex];
          Serial.println(arrayindex);
        }
        display.drawBitmap(j * 8 - mapX, i * 8,  currentTile, 8, 8, 0);
      }
    }
  }
}
