#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "tiles.h"
#include "tilemap.h"



#define OLED_RESET 4 // not used / nicht genutzt bei diesem Display
Adafruit_SSD1306 display(OLED_RESET);
const int buttonPin = 16;
const int buttonPin2 = 14;
int buttonState = 0;         // variable for reading the pushbutton status
int button2State = 0;
int mapX = 0;

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
  display.display();
}

void loop() {
  display.clearDisplay();
  display.fillScreen(1);
  printArray(TileMap);
  buttonState = digitalRead(buttonPin);
  button2State = digitalRead(buttonPin2);

  if (buttonState == LOW) {
    mapX+= 8;
  }
  if (button2State == LOW && mapX > 0) {
    mapX-= 8;
  }
  
  display.display();
}

void printArray( const int a[][ columns ] ) {
  // loop through array's rows
  for ( int i = 0; i < rows; ++i ) {
    // loop through columns of current row
    for ( int j = 0; j < columns; ++j ) {
      //  display.print (a[ i ][ j ] );
      int c = a[i][j];
      //B(j * 8 , i * 8, c);
      if (c > 0){
        display.drawBitmap(j*8 - mapX, i*8,  TileSet[c - 1], 8, 8, 0);
      }
    // display.print(c);
    }
  }
  delay(0);
}
