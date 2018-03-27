// 
// 
// 

#include "Driving.h"


void DrivingClass::init(const uint8_t _PinMotorLeftSpeed, const uint8_t _PinMotorLeftDirection, const uint8_t _PinMotorRightSpeed, const uint8_t _PinMotorRightDirection) {
	this->setPinSpeed(_PinMotorRightSpeed, MOTOR_RIGHT)
		->setPinDirection(_PinMotorRightDirection, MOTOR_RIGHT)
		->setPinSpeed(_PinMotorLeftSpeed, MOTOR_LEFT)
		->setPinDirection(_PinMotorLeftDirection, MOTOR_LEFT);
};
void DrivingClass::drive(uint8_t Speed, bool Direction = DIR_FORWARD){
	this->setSpeed(Speed, MOTOR_LEFT)
		->setDirection(Direction, MOTOR_LEFT)
		->enable(MOTOR_LEFT);
	this->setSpeed(Speed, MOTOR_RIGHT)
		->setDirection(Direction, MOTOR_RIGHT)
		->enable(MOTOR_RIGHT);
};

void DrivingClass::halt() {
	this->disable(MOTOR_LEFT);
	this->disable(MOTOR_RIGHT);
};

DrivingClass* DrivingClass::setPinSpeed(const uint8_t _PinSpeed, const uint8_t _Motor) {
	this->_PinSpeed[_Motor] = _PinSpeed;
	pinMode(this->_PinSpeed[_Motor], OUTPUT);
	return this;
};
DrivingClass* DrivingClass::setPinDirection(const uint8_t _PinDirection, const uint8_t _Motor) {
	this->_PinDirection[_Motor] = _PinDirection;
	pinMode(this->_PinDirection[_Motor], OUTPUT);
	return this;
};
DrivingClass* DrivingClass::setSpeed(const uint8_t _Speed, const uint8_t _Motor) {
	this->_Speed[_Motor] = this->limitSpeed(_Speed);
	return this;
};
DrivingClass* DrivingClass::setDirection(const bool _Direction, const uint8_t _Motor) {
	this->_Direction[_Motor] = _Direction;
	return this;
};
void DrivingClass::enable(const bool _Motor) {
	analogWrite(this->_PinSpeed[_Motor], (this->_Direction[_Motor] == DIR_FORWARD) ? 255 - this->_Speed[_Motor] : this->_Speed[_Motor]);
	digitalWrite(this->_PinDirection[_Motor], this->_Direction[_Motor]);
};

void DrivingClass::disable(const bool _Motor) {
	digitalWrite(this->_PinSpeed[_Motor], 0);
	digitalWrite(this->_PinDirection[_Motor], 0);
};

int DrivingClass::limitSpeed(uint8_t Speed) {
	if (Speed < MIN_SPEED) {
		return (uint8_t) MIN_SPEED;
	} else if(Speed > MAX_SPEED) {
		return (uint8_t) MAX_SPEED;
	}
	return Speed;
};



DrivingClass Driving;

