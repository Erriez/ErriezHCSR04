# HC-SR04 Ultrasonic Distance Sensor library for Arduino

[![Build Status](https://travis-ci.org/Erriez/ErriezHCSR04.svg?branch=master)](https://travis-ci.org/Erriez/ErriezHCSR04)

This is a HC-SR04 I2C RTC library for Arduino.

![HC-SR04 sensor](https://raw.githubusercontent.com/Erriez/ErriezHCSR04/master/extras/HC-SR04.png)


## Library features

* Measure distance between 2..2000 cm
* Accuracy around +/-1cm
* Optimized pin control for AVR


## Hardware

**Arduino UNO**

* TRIG pin to Arduino Uno pin 2
* ECHO pin to Arduino Uno pin 3
* VCC pin to Arduino Uno pin VCC
* GND pin to Arduino Uno pin GND

![Arduino Uno HC-SR04](extras/Arduino-Uno-HC-SR04.png)


## Examples

Arduino IDE | Examples | Erriez HC-SR04:

* [HC-SR04](https://github.com/Erriez/ErriezHCSR04/blob/master/examples/ErriezHCSR04/ErriezHCSR04.ino)


## Documentation

* [Doxygen online HTML](https://erriez.github.io/ErriezHCSR04)
* [Doxygen PDF](https://github.com/Erriez/ErriezHCSR04/blob/master/ErriezHCSR04.pdf)


## Example

```c++
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
    uint16_t distance;

    // Measure distance
    distance = hcsr04.getDistance();
    
    // Print distance
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Wait
    delay(250);
}
```


## Library dependencies

* None


## Library installation

Please refer to the [Wiki](https://github.com/Erriez/ErriezArduinoLibraries/wiki) page.


## More Arduino Libraries from Erriez

* [Erriez Libraries](https://github.com/Erriez/ErriezArduinoLibraries)
