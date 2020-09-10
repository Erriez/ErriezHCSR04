/*
 * MIT License
 *
 * Copyright (c) 2020 Erriez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*!
 * \file ErriezHCSR04.h
 * \brief HC-SR04 ultrasonic distance sensor library for Arduino
 * \details
 *      Source:         https://github.com/Erriez/ErriezHCSR04
 *      Documentation:  https://erriez.github.io/ErriezHCSR04
 */

#ifndef ERRIEZ_HCSR04_H_
#define ERRIEZ_HCSR04_H_

#include <Arduino.h>


#ifdef __AVR
#define HCSR04_TRIG_LOW()        { *portOutputRegister(_triggerPort) &= ~_triggerBit; }  //!< Trigger pin low
#define HCSR04_TRIG_HIGH()       { *portOutputRegister(_triggerPort) |= _triggerBit; }   //!< Trigger pin high
#define HCSR04_TRIG_OUTPUT()     { *portModeRegister(_triggerPort) |= _triggerBit; }     //!< Trigger pin output

#define HCSR04_ECHO_INPUT()      { *portModeRegister(_echoPort) &= ~_echoBit; }    //!< Echo pin input
#define HCSR04_ECHO_READ()       ( *portInputRegister(_echoPort) & _echoBit )      //!< Echo pin read
#else
#define HCSR04_TRIG_LOW()        { digitalWrite(_triggerPin, LOW); }     //!< Trigger pin low
#define HCSR04_TRIG_HIGH()       { digitalWrite(_triggerPin, HIGH); }    //!< Trigger pin high
#define HCSR04_TRIG_OUTPUT()     { pinMode(_triggerPin, OUTPUT); }       //!< Trigger pin output

#define HCSR04_ECHO_INPUT()      { pinMode(_echoPin, INPUT); }          //!< Echo pin input
#define HCSR04_ECHO_READ()       ( digitalRead(_echoPin) )              //!< Echo pin read
#endif

/*!
 * \brief ErriezHCSR04 class
 */
class ErriezHCSR04
{
public:
    // Constructor
    ErriezHCSR04(uint8_t triggerPin, uint8_t echoPin);

    // Initialize
    void begin();

    // Get distance in cm
    uint16_t getDistance();

private:
#ifdef __AVR
    uint8_t _triggerPort;   //!< Trigger port in IO pin register
    uint8_t _echoPort;      //!< Echo port in IO pin register

    uint8_t _triggerBit;    //!< Trigger bit number in IO pin register
    uint8_t _echoBit;       //!< Echo bit number in IO pin register
#else
    uint8_t _triggerPin;    //!< Trigger pin
#endif
    uint8_t _echoPin;       //!< Echo pin
};

#endif // ERRIEZ_HCSR04_H_
