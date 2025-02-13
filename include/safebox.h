#pragma once
#include <Arduino.h>
#include <OneButton.h>
#include <Encoder.h>
#include <Servo.h>
#include "common_def.h"
#include "gui.h"
//#include "VarSpeedServo.h"
#include "lights.h"

class Safebox
{
public:
    Safebox() : _enc(KNOB_CLK_PIN, KNOB_DT_PIN), _but(KNOB_BUT_PIN) {}

    void begin(void);
    void run(void);

    state_e getStep(void);

private:
    Gui _display;
    //VarSpeedServo _servo;
    Servo _servo;
    Lights _leds;
    Encoder _enc;
    OneButton _but;

    state_e _actStep;
    unsigned int _newEvent = 0;

    unsigned int _codeActNum[4] = {0, 0, 0, 0};

    int servoPos = 0;

    volatile long _oldEncPos = -999;
    volatile long _newEncPos = 0;

    void _setStep(state_e step);
    void _nextStep(void);
    void _prevStep(void);
    void _stepManager(void);

    void _stepLock(void);
    void _stepMainPage(void);
    void _stepFirstNum(void);
    void _stepSecondNum(void);
    void _stepThirdNum(void);
    void _stepFourthNum(void);
    void _stepUnlocked(void);

    void _encoderManager(void);
    void _newEncoderEvent(void);
    void _encoderEventAdd(void);
    void _encoderEventSub(void);

    void _checkCode(void);
    void _checkCodeNum(unsigned int pos);
    void _checkCodeNum1(void);
    void _checkCodeNum2(void);
    void _checkCodeNum3(void);
    void _checkCodeNum4(void);
    void _wrongCodeProcedure(void);
    void _codeOKProcedure(void);

    void _lockDoor(void);
    void _unlockDoor(void);

    void _singleClickEvent(void);
    void _doubleClickEvent(void);
};