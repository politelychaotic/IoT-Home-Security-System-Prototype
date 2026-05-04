# IoT-Home-Security-System-Prototype
Arduino-based prototype security system combining intrusion detection and environmental   monitoring. Built with C++ on Arduino hardware using multiple sensor types.

## Features

  - **Intrusion detection** — ultrasonic sensor oriented toward entry points; triggers red
  LED + buzzer on proximity alert
  - **Temperature & humidity monitoring** — DHT sensor with live readout via Arduino Serial
  Monitor; designed for AC control in a deployed system
  - **Automated lighting** — light sensor detects low-light conditions, triggers blue LED
  - **Flood detection** — water level sensor triggers red LED alert on high water

  ## Hardware

  | Component | Purpose |
  |---|---|
  | Arduino | Microcontroller |
  | Ultrasonic sensor | Door/intrusion detection |
  | DHT sensor | Temperature + humidity |
  | Light sensor | Ambient light monitoring |
  | Water level sensor | Flood detection |
  | LEDs (red, green, blue) | Visual status indicators |
  | Buzzer | Audio alert |
  | Breadboard | Prototyping |

  ## Alert Logic

  | Condition | Indicator |
  |---|---|
  | Door clear | Green LED |
  | Intrusion detected | Red LED + buzzer |
  | Low light | Blue LED |
  | High water level | Red LED |
  | Temp/humidity | Serial Monitor output |

  ## Demo

  ![Circuit diagram](assets/circuit.jpg)
  ![Prototype build](assets/prototype.jpg)

  ## Usage

  1. Wire components per the circuit diagram above
  2. Open `home_security.ino` in Arduino IDE
  3. Upload to Arduino board
  4. Open Serial Monitor (9600 baud) to view temperature and humidity readings

  ## What This Demonstrates

  - Multi-sensor integration on a single microcontroller
  - Real-time environmental monitoring with C++
  - Hardware prototyping and breadboard circuit design
  - Alert system design with distinct visual + audio outputs per condition
