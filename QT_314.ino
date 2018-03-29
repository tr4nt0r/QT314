#include <TimerOne.h>
#include "Driving.h"
#include <NewPing.h>


const uint8_t TRIGGER_PIN = 10;
const uint8_t ECHO_PIN = 11;

const uint8_t LED_BLUE = 2;
const uint8_t LED_RED = 4;

const uint8_t PIN_MOTOR1_PWM = 8;
const uint8_t PIN_MOTOR1_DIR = 9;

const uint8_t PIN_MOTOR2_PWM = 7;
const uint8_t PIN_MOTOR2_DIR = 6;

volatile bool toggleLED = 1;

NewPing Sonar(TRIGGER_PIN, ECHO_PIN);


void setup()
{
  /* add setup code here */
	Serial.begin(9600);
	pinMode(LED_BLUE, OUTPUT);
	pinMode(LED_RED, OUTPUT);
	
	Timer1.initialize(500000);
	Timer1.attachInterrupt(blinkLED);

	Driving.init(PIN_MOTOR2_PWM, PIN_MOTOR2_DIR, PIN_MOTOR1_PWM, PIN_MOTOR1_DIR);	
	Driving.drive(MAX_SPEED, DIR_FORWARD);
	Serial.println("Start driving forward...");
	delay(1000);
	
	Driving.drive(MAX_SPEED, DIR_BACKWARD);
	Serial.println("Start driving backwards...");
	delay(1000);

	Driving.turn(MAX_SPEED, DIR_LEFT);
	Serial.println("Start turning left...");
	delay(5000);
	
	Driving.halt();
	Serial.println("Stop driving...");
}

void loop()
{


	
}


void blinkLED() {
	//Serial.println(toggleLED);
	if (Driving.isDriving()) {
		digitalWrite(LED_BLUE, toggleLED);
		toggleLED ^= 1;
		digitalWrite(LED_RED, toggleLED);
	}
}
