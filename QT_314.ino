#include <TimerOne.h>
#include "Driving.h"
#include <NewPing.h>

#define MAX_SPEED 225
#define MIN_SPEED 50

const uint8_t TRIGGER_PIN = 10;
const uint8_t ECHO_PIN = 11;

const uint8_t LED_BLUE = 2;
const uint8_t LED_RED = 4;

const uint8_t PIN_MOTOR1_PWM = 10;
const uint8_t PIN_MOTOR1_DIR = 8;

const uint8_t PIN_MOTOR2_PWM = 9;
const uint8_t PIN_MOTOR2_DIR = 7;

volatile bool toggleLED = 1;

NewPing Sonar(TRIGGER_PIN, ECHO_PIN);


void setup()
{
  /* add setup code here */
	Serial.begin(9600);
	pinMode(LED_BLUE, OUTPUT);
	pinMode(LED_RED, OUTPUT);
	
	//Timer1.initialize(500000);
	//Timer1.attachInterrupt(blinkLED);

	Driving.init(PIN_MOTOR2_PWM, PIN_MOTOR2_DIR, PIN_MOTOR1_PWM, PIN_MOTOR1_DIR);	
	
	Driving.drive(MAX_SPEED, DIR_FORWARD);
	delay(5000);
	Driving.halt();
	delay(1000);
	Driving.drive(MIN_SPEED, DIR_FORWARD);
	delay(5000);
	Driving.halt();
	delay(1000);
	Driving.drive(MAX_SPEED, DIR_BACKWARD);
	delay(5000);
	Driving.halt();
}

void loop()
{

}


void blinkLED() {
	if (Driving.isDriving()) {
		digitalWrite(LED_BLUE, toggleLED);
		toggleLED ^= 1;
		digitalWrite(LED_RED, toggleLED);
	}
}
