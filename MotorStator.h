#ifndef MOTORSTATOR_H
#define MOTORSTATOR_H

#define MOTOR_INTERFACE_TYPE 1 //1 означает внешний шаговый драйвер с выводами Step и Direction
#define ACCELERATION 3000
#define MAX_SPEED 60000

#include <AccelStepper.h>
#include "Motor.h"

class MotorStator {
public:
    int stepPin;
    int dirPin;
    int limitPin;

    AccelStepper accelStepper;
    int stepPer360;

    MotorStator(int stepPin, int dirPin, int stepPer360) : accelStepper(MOTOR_INTERFACE_TYPE, stepPin, dirPin) {

    };

    void setup() {
        accelStepper.setMaxSpeed(MAX_SPEED);
        accelStepper.setAcceleration(ACCELERATION);
    };

    void moveTo(double grad) {
        accelStepper.moveTo(int(stepPer360 / 360 * grad));
        accelStepper.runSpeedToPosition();
    };

};
#endif // MOTORSTATOR_H
