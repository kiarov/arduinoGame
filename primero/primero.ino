#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "tiles.h"
#include "chars.h"
#include "tilemap.h"

#define OLED_RESET 4 // not used 
Adafruit_SSD1306 display(OLED_RESET);
const int buttonPin = 16;
const int buttonPin2 = 14;
int buttonState = 0;         // variable for reading the pushbutton status
int button2State = 0;
int screenX = 0;      // the fisical position where we start drawing the screen
int screenStart = 0;  //first column from the tilemap we want to draw on screen
int screenEnd = 17;   //last column from the tilemap we want to draw on screen
int scrollArea = 128; // basically the width of the 1306 display
int scrollDifference = 0;  //the ammount of columns we have to draw at each screen refresh;
int period = 100; //the time that animations have to change frame
unsigned long frameTime = 0;

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
  //Serial.begin(9600);
}

void loop() {

  display.clearDisplay();
  display.fillScreen(1); //We fill the screen with white so we could draw our objects in black

  scrollDifference = (screenX / 8); // we must update this value everytime
  buttonState = digitalRead(buttonPin);
  button2State = digitalRead(buttonPin2);
  if (buttonState == HIGH && button2State == HIGH) {
    charFrame = 0;
  }
  if (buttonState == LOW && screenX < screenWidth - 128) {
    screenX += 4;
    animate(charFrame);
    if (charPos < 64 - 8) {
      charPos += 2;
    }
    if (screenStart < columns - 15) {
      screenStart = scrollDifference;
    }
    if (screenEnd < columns) {
      screenEnd = scrollDifference + 17;
    }
  }
  if (button2State == LOW && screenX > 0) {
    screenX -= 4; //cant be higher than columns -16
    if (charPos > 0) {
      charPos -= 2;
    }
    if (screenStart - scrollDifference > 0) {
      if (screenX <= 0 ) {
        screenX = 0;
        screenStart = 0;
      }
      screenStart = scrollDifference;
    }
    if (scrollDifference + 17 <= columns) {
      screenEnd = scrollDifference + 17;
    }
  }
  printArray(TileMap);
  display.setCursor(3, 3);
  display.print(charFrame);
  //  display.print(screenWidth);
  //  display.print(":");
  //  display.print(screenX);
  //  display.print(":");
  //  display.print(scrollDifference);
  //  display.print(":");
  //  display.print(screenStart);
  //  display.print(":");
  //  display.print(screenEnd);
  //  display.print(":");
  //  display.print(screenEnd + scrollDifference);
  display.drawBitmap(charPos, 33,  hilario[charFrame], 16, 24, 0);
  display.display();
};

void animate (int frame) {
  display.print(charFrame);
  charFrame = 1;
  if (millis() > frameTime + period) {
    charFrame = 2;
    frameTime = millis();
  }
}


void printArray( const int a[][columns] ) {
  // loop through array's rows
  for ( int i = 0; i < rows; ++i ) {
    // loop through columns of current row
    for ( int j = screenStart ; j < screenEnd; ++j ) {
      // c equals current cell value
      int c = a[i][j];
      if (c > 0) {
        int newc = c - 1;
        display.drawBitmap(j * 8 - screenX, i * 8,  TileSet[newc], 8, 8, 0);
      }

    }
  }
}
