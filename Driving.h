// Driving.h

#ifndef _DRIVING_h
#define _DRIVING_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef DIR_FORWARD
	#define DIR_FORWARD 1
#endif // !DIR_FORWARD

#ifndef DIR_BACKWARD
	#define DIR_BACKWARD 0
#endif // !DIR_BACKWARD

#ifndef DIR_LEFT
#define DIR_LEFT 0
#endif // !DIR_LEFT

#ifndef DIR_RIGHT
#define DIR_RIGHT 1
#endif // !DIR_RIGHT

#ifndef MAX_SPEED
	#define MAX_SPEED 255
#endif // !MAX_SPEED

#ifndef MIN_SPEED
#define MIN_SPEED 80
#endif // !MIN_SPEED

#define MOTOR_LEFT 0
#define MOTOR_RIGHT 1

class DrivingClass {
 protected:


 public:
	void init(const uint8_t PinMotorLeftSpeed, const uint8_t PinMotorLeftDirection, const uint8_t PinMotorRightSpeed, const uint8_t PinMotorRightDirection);
	void drive(uint8_t Speed, bool Direction = DIR_FORWARD);
	void halt();
	void turn(uint8_t Speed = MAX_SPEED, uint8_t Direction = DIR_LEFT);
	bool isDriving();

 private:
	 uint8_t _PinSpeed[2] = {}; //PWM Pins
	 uint8_t _PinDirection[2] = {}; //Direction Pins
	 uint8_t _Speed[2] = {}; //PWM Speed for Motors
	 bool _Direction[2] = {};  //direction of the Motors
	 bool _isDriving[2] = { false, false }; //driving status of Motors
	 
	 DrivingClass* setPinSpeed(const uint8_t _PinSpeed, const uint8_t _Motor);
	 DrivingClass* setPinDirection(const uint8_t _PinDirection, const uint8_t _Motor);

	 DrivingClass* setSpeed(const uint8_t _Speed, const uint8_t _Motor);
	 DrivingClass* setDirection(const bool _Direction, const uint8_t _Motor);	 
	 void enable(const bool _Motor);
	 void disable(const bool _Motor);
	 int limitSpeed(uint8_t Speed);	
};

extern DrivingClass Driving;

#endif

