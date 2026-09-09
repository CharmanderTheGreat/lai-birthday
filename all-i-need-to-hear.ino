#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct WordStep {
  unsigned long timeMs;
  const char* word;
  uint8_t col;
  uint8_t row;
  bool clearScreen;
};

const WordStep lyrics[] = {
  {   480, "Oh,",          0, 0, true  },
  {  1000, "I",            4, 0, false },
  {  1360, "don't",        6, 0, false },
  {  1860, "care",        12, 0, false },
  {  2420, "if",           0, 1, false },
  {  2720, "you're",       3, 1, false },
  {  3700, "insincere",    0, 0, true  },
  {  6920, "Just",         0, 1, false },
  {  7200, "tell",         5, 1, false },
  {  7660, "me",          10, 1, false },
  {  8060, "what",         0, 0, true  },
  {  8400, "I",            5, 0, false },
  {  8980, "wanna",        7, 0, false },
  {  9680, "hear",         0, 1, false },
  { 12300, "You",          0, 0, true  },
  { 12460, "know",         4, 0, false },
  { 12920, "where",        9, 0, false },
  { 13440, "to",           0, 1, false },
  { 13660, "find",         3, 1, false },
  { 14060, "me",           8, 1, false },
  { 14960, "The",          0, 0, true  },
  { 15120, "place",        4, 0, false },
  { 15660, "where",       10, 0, false },
  { 16080, "we",           0, 1, false },
  { 16280, "lived",        3, 1, false },
  { 16960, "all",          9, 1, false },
  { 17360, "these",        0, 0, true  },
  { 18180, "years,",       6, 0, false },
  { 19420, "oh",           0, 1, false },
  { 22730, "and",          3, 1, false },
  { 23110, "tell",         7, 1, false },
  { 23630, "me",          12, 1, false },
  { 23970, "you",          0, 0, true  },
  { 24230, "love",         4, 0, false },
  { 24630, "me",           9, 0, false },
  { 25750, "That's",       0, 1, false },
  { 26290, "all",          7, 1, false },
  { 26630, "that",        11, 1, false },
  { 26890, "I",            0, 0, true  },
  { 27530, "need",         2, 0, false },
  { 27970, "to",           7, 0, false },
  { 28970, "hear",        10, 0, false }
};

const int totalWords = sizeof(lyrics) / sizeof(lyrics[0]);
int currentWordIndex = 0;
unsigned long startPlaybackTime = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("@rence.szkyrob");
  delay(1300);
  lcd.clear();
  startPlaybackTime = millis();
}

void loop() {
  unsigned long elapsed = millis() - startPlaybackTime;
  if (currentWordIndex < totalWords) {
    if (elapsed >= lyrics[currentWordIndex].timeMs) {
      if (lyrics[currentWordIndex].clearScreen) {
        lcd.clear();
      }
      lcd.setCursor(lyrics[currentWordIndex].col, lyrics[currentWordIndex].row);
      lcd.print(lyrics[currentWordIndex].word);
      currentWordIndex++;
    }
  }
}
