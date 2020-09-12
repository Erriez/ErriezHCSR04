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
 * \brief HC-SR04 ultrasonic distance sensor example for Arduino
 * \details
 *    Measurement range between 2..2000 cm +/-1cm
 *
 *    Source:         https://github.com/Erriez/ErriezHCSR04
 *    Documentation:  https://erriez.github.io/ErriezHCSR04
 */

#include <ErriezHCSR04.h>

// Pin defines
#define TRIG_PIN    2
#define ECHO_PIN    3

// Create sensor object
ErriezHCSR04 hcsr04(TRIG_PIN, ECHO_PIN);


void setup()
{
    // Initialize serial port
    delay(500);
    Serial.begin(115200);
    while (!Serial) {
        ;
    }
    Serial.println(F("\nErriez HC-SR04 ultrasonic distance sensor example\n"));

    // Initialize pins
    hcsr04.begin();
}

void loop()
{
    float distance;

    // Measure distance in Inch
    distance = hcsr04.getDistanceInch();

    // Print distance
    Serial.print(F("Distance: "));
    if (distance >= 0) {
        Serial.print(distance);
        Serial.println(F("\""));
    } else {
        Serial.println(("-"));
    }

    // Wait
    delay(250);
}