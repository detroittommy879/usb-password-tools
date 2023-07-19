
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keyboard.h>
//#include <Rotary.h>
//#include <Encoder.h>

#define SCREEN_ADDRESS 0x3D
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

//const int encButton = A0;
//const int encButton2 = A1;


const int keyDelay = 200;
const int upButtonPin = 14;    // Pin for the "Up" button
const int downButtonPin = 9;   // Pin for the "Down" button
const int sendButtonPin = 16;  // Pin for the "Send" button


//const int numStrings = 4;  // Number of strings in the array
//String displayText = "Select Password: ";
char displayText[] = "Select entry: ";

struct KeyDescription {
  const char* description;
  const char* keyValue;
};

KeyDescription keyDescriptions[] = {
  { "1 wxyz", "1qaz1qaz000033333" },
  { "2 username5", "dUH8J2F012GMA1I8kx@EFkbmMaaa036545VDxSaEbwTYVxwrVEjQbeSI7skSwBE6sK" },
  { "3 ssh", "2345234525636734652343563635emfjfjdjkdjGRGETHGSHdgh" },
  { "4 sudo", "1qazedwdwdzzeedw1qaz" },
  { "5 user1", "L1QmrPdewdwdewq7CE2u2gjwZ8m8pvRnXjTMZJpUfcjyLTApd21fnstgbZ8h" },
  { "6 gmail", "1qazdewdwd1qaz" },
  { "7", "1qazwfewwwffw1qaz" },
  { "8", "0000011111222223333344444555556666677777888889999900000" },
  { "9", "11111111fefeefefefratestringofwordsfromdictionary..00000000" }

};

const int numStrings = sizeof(keyDescriptions) / sizeof(keyDescriptions[0]);  // Number of strings in the array
const int maxIndex = numStrings - 1;                                          // Maximum index value

int currentIndex = 0;  // Current index of the selected string

// OLED display settings
#define OLED_RESET 5
Adafruit_SSD1306 display(OLED_RESET);
//Rotary rrr = Rotary(8,9);

//Encoder myEnc(encButton, encButton2);

void setup() {
  //pinMode(encoderPinA, INPUT_PULLUP);
  //pinMode(encoderPinB, INPUT_PULLUP);
  //digitalWrite(encoderPinA, HIGH);
  //digitalWrite(encoderPinB, HIGH);
  //pinMode(encButton, INPUT_PULLUP);
  //pinMode(encButton2, INPUT_PULLUP);

  pinMode(upButtonPin, INPUT_PULLUP);
  pinMode(downButtonPin, INPUT_PULLUP);
  pinMode(sendButtonPin, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(500);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  Keyboard.begin();

}
 



  void loop() {
    if (digitalRead(upButtonPin) == LOW) {
      currentIndex = currentIndex + 1;
      if (currentIndex >= numStrings) {
        currentIndex = 0;
      }

      delay(keyDelay);  // Debounce delay
    }

    if (digitalRead(downButtonPin) == LOW) {
      currentIndex = currentIndex - 1;  // Cycle to the previous string
      if (currentIndex < 0) {
        currentIndex = maxIndex;

      }
      delay(keyDelay);                                              // Debounce delay
    }

    if (digitalRead(sendButtonPin) == LOW) {
      sendString(keyDescriptions[currentIndex].keyValue);
      delay(keyDelay);  // Debounce delay
    }

    display.clearDisplay();
    display.setCursor(1, 1);
    display.println(displayText);
    display.println(keyDescriptions[currentIndex].description);
    display.display();

  }



  void sendString(const char* str) {
    Keyboard.print(str);  // Send the selected string as keyboard presses
    //  Keyboard.press(KEY_RETURN);
    //  Keyboard.releaseAll();
  }



