#include "Driving.h"
#include <NewPing.h>


const uint8_t TRIGGER_PIN = 10;
const uint8_t ECHO_PIN = 11;

const uint8_t LED_BLUE = 2;
const uint8_t LED_RED = 3;

const uint8_t PIN_MOTORA_PWM = 9;
const uint8_t PIN_MOTORA_DIR = 8;

const uint8_t PIN_MOTORB_PWM = 7;
const uint8_t PIN_MOTORB_DIR = 6;


NewPing Sonar(TRIGGER_PIN, ECHO_PIN);


void setup()
{
  /* add setup code here */
	Serial.begin(9600);
	pinMode(LED_BLUE, OUTPUT);
	pinMode(LED_RED, OUTPUT);
	
	Driving.init(PIN_MOTORA_PWM, PIN_MOTORA_DIR, PIN_MOTORB_PWM, PIN_MOTORB_DIR);	
	Driving.drive(MAX_SPEED, DIR_FORWARD);
}

void loop()
{
	
}
