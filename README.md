# Bluetooth Controlled Robot

A smartphone controlled robot operated
wirelessly via Bluetooth using an HC-05
module and a Bluetooth RC Controller
Android application.

## Components Used
- Arduino Uno
- HC-05 Bluetooth Module
- L298N Motor Driver
- 2x DC TT Gear Motors
- 9V Battery Pack
- Robot Chassis + Wheels
- 1k and 2k Ohm Resistors for voltage divider

## How It Works
The HC-05 module receives single character
commands from the phone app over Bluetooth
serial communication. Arduino reads each
character and executes the matching motor
action via the L298N driver.

| Command | Action        |
|---------|---------------|
| F       | Move Forward  |
| B       | Move Backward |
| L       | Turn Left     |
| R       | Turn Right    |
| S       | Stop          |

## Pin Configuration
| Component     | Arduino Pin             |
|---------------|-------------------------|
| HC-05 TX      | Pin 10                  |
| HC-05 RX      | Pin 11 via voltage divider |
| L298N IN1     | Pin 2                   |
| L298N IN2     | Pin 3                   |
| L298N IN3     | Pin 4                   |
| L298N IN4     | Pin 5                   |
| L298N ENA     | Pin 9 PWM               |
| L298N ENB     | Pin 6 PWM               |

## Voltage Divider Note
HC-05 RX pin runs on 3.3V but Arduino
outputs 5V. A voltage divider using 1k
and 2k Ohm resistors brings it down to
safe 3.3V to protect the module.

## App Used
Bluetooth RC Controller available free
on Google Play Store.

## Libraries Used
- SoftwareSerial.h (built in)

## Skills Demonstrated
- Bluetooth serial communication
- Wireless command parsing
- Switch case logic
- Voltage divider circuit protection
- Mobile to hardware interfacing
- Embedded C programming in Arduino IDE
