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

#include "ErriezHCSR04.h"


/*!
 * \brief Constructor
 * \param triggerPin
 *      Trigger pin
 * \param echoPin
 *      Echo pin
 */
ErriezHCSR04::ErriezHCSR04(uint8_t triggerPin, uint8_t echoPin)
{
    // Save pins
#ifdef __AVR
    _triggerPort = digitalPinToPort(triggerPin);
    _echoPort = digitalPinToPort(echoPin);

    _triggerBit = digitalPinToBitMask(triggerPin);
    _echoBit = digitalPinToBitMask(echoPin);
#else
    _triggerPin = triggerPin;
#endif
    _echoPin = echoPin;
}

/*!
 * \brief Initialize pins
 */
void ErriezHCSR04::begin()
{
    // TRIG pin output low
    HCSR04_TRIG_LOW();
    HCSR04_TRIG_OUTPUT();

    // ECHO pin input
    HCSR04_ECHO_INPUT();
}

/*!
 * \brief Get distance in cm
 * \retval -1
 *      Out of range
 * \retval 0..400cm
 *      Distance in cm
 */
int16_t ErriezHCSR04::getDistance()
{
    uint16_t distance;

    // Wait at least 2 microseconds with TRIG pin low before starting measurement
    HCSR04_TRIG_LOW();
    delayMicroseconds(2);

    // Generate 10 ms pulse TRIG pin
    HCSR04_TRIG_HIGH();
    delayMicroseconds(10);
    HCSR04_TRIG_LOW();

    // Reads the ECHO pin, returns the sound wave travel time in microseconds
    // Distance = (high level time * velocity (340M/S)) / 2;
    distance = (pulseIn(_echoPin, HIGH) * 0.034) / 2;

    // Max range is around 400cm
    if (distance > 400) {
        // Invalid distance
        distance = -1;
    }

    return distance;
}

/*!
 * \brief Get distance in Inch
 * \retval -1
 *      Out of range
 * \retval 0.00" .. 157.48"
 *      Distance in inch
 */
float ErriezHCSR04::getDistanceInch()
{
    int16_t distanceCm;

    // Read distance in centimeter
    distanceCm = getDistance();

    if (distanceCm >= 0) {
        // Convert cm to inch
        return (float)distanceCm / 2.54;
    } else {
        // Invalid distance
        return -1.0;
    }
}
