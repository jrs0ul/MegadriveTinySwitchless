#include <EEPROM.h>

const int RESET_BUTTON = 4;
const int RESET_SIGNAL = 3;
const int LANGUAGE_SIGNAL = 0;
const int HZ_MODE_SIGNAL = 1;

enum ConsoleModes
{
  USA = 0,
  JAPAN,
  EURO
};

int resetState = 0;
int resetCounter = 0;
bool reseted = false;
uint8_t currentMode = USA;

void setRegion() 
{
  if (currentMode > EURO) 
  {
    currentMode = USA;
  }
  switch (currentMode) 
  {
    case USA:
      {
        digitalWrite(LANGUAGE_SIGNAL, HIGH);
        //digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(HZ_MODE_SIGNAL, HIGH);
      }
      break;
    case JAPAN:
      {
        digitalWrite(LANGUAGE_SIGNAL, LOW);
        //digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(HZ_MODE_SIGNAL, HIGH);
      }
      break;
    case EURO:
      {
        digitalWrite(LANGUAGE_SIGNAL, HIGH);
        //digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(HZ_MODE_SIGNAL, LOW);
      }
      break;
  }
  EEPROM.put(0, currentMode);
}


void setup() 
{
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RESET_BUTTON, INPUT_PULLUP);
  pinMode(RESET_SIGNAL, OUTPUT);
  pinMode(LANGUAGE_SIGNAL, OUTPUT);
  pinMode(HZ_MODE_SIGNAL, OUTPUT);

  currentMode = EEPROM.read(0);
  setRegion();
}

void loop() 
{
  resetState = digitalRead(RESET_BUTTON);

  if (!resetState) 
  {
    while (!resetState) 
    {
      delay(100);
      ++resetCounter;
      if (resetCounter >= 10) 
      {
        resetCounter = 0;
        digitalWrite(RESET_SIGNAL, LOW);
        delay(10);
        digitalWrite(RESET_SIGNAL, HIGH);
        reseted = true;
        break;
      }

      resetState = digitalRead(RESET_BUTTON);
      if (resetState && !reseted)
      {
        ++currentMode;
        setRegion(); 
      }
    }
  } 
  else // RESET not pressed
  {
    resetCounter = 0;
    reseted = false;
  }
}
