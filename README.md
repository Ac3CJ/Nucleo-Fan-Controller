<p align="center"><img src="https://cdn-icons-png.flaticon.com/512/6475/6475231.png" alt="FAN Logo" width="100"></p>
<h1 align="center"> Fan Controller Board </h1>

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![License](https://img.shields.io/badge/license-MIT-blue)

This project features a fan controller board designed using the NUCLEO-F070RB development board. The board offers three modes of operation, allowing users to control and monitor the fan's behavior through various user interfaces.

---

## Table of Contents

- [Introduction](#introduction)  
- [Features](#features)  
- [Modes of Operation](#modes-of-operation)  
- [Interfaces](#interfaces)  
- [Display Functionality](#display-functionality)  
- [Setup](#setup)  
- [Usage](#usage)  
- [License](#license)  

---

## Introduction  

The fan controller board provides robust control over fan operation, supporting open loop and closed loop control schemes. It integrates intuitive interfaces for input and output, making it a versatile tool for a range of applications.  

---

## Features  

- **Modes of Operation**:  
  - Open Loop Control  
  - Closed Loop Control with User-Variable Fan Speed  
  - Closed Loop Control with Temperature Measurements  

- **User Interfaces**:  
  - **Inputs**:
    - Rotary encoder (Extension board)
    - Button  
  - **Visual Outputs**:  
    - 2-digit 7-segment display (HDSP-521E)  
    - LCD screen (ST7066U)  
    - LEDs (Board and Extension board)  
    - Temperature sensor (TC74)  

- **Real-Time Feedback** for fan control and monitoring.  

---

## Modes of Operation  

1. **Open Loop Control**:  
   - The fan runs at a user-set duty cycle.  
   - Duty cycle is adjustable using the rotary encoder.  

2. **Closed Loop Control with Variable Fan Speed**:  
   - The fan speed is controlled to match a user-defined target RPM.  
   - Rotary encoder is used to set the target RPM.  

3. **Closed Loop Control with Temperature Measurements**:  
   - The fan speed adjusts automatically based on the measured temperature.  
   - No rotary encoder input is needed in this mode.  

---

## Interfaces  

### User Inputs  
- **Rotary Encoder**:  
  - Adjusts duty cycle in Open Loop Mode.  
  - Sets target RPM in Closed Loop Fan Speed Mode.  
  - Unused in Closed Loop Temperature Mode.  

- **Button**:  
  - Toggles between the three modes.  

### Visual Outputs  
- **2-Digit 7-Segment Display**:  
  - Displays:  
    - Current duty cycle (%) in Open Loop Mode.  
    - Percentage error between target RPM and current RPM in Closed Loop Fan Speed Mode.  
    - Current temperature from the TC74 sensor in Closed Loop Temperature Mode.  

- **LCD Screen**:  
  - Displays:  
    - **First Line**:  
      - Time delta for speed readings in Open Loop Mode.  
      - Target RPM in Closed Loop Fan Speed Mode.  
      - Target temperature in Closed Loop Temperature Mode.
    - **Second Line**: Current fan speed in all modes.  

- **LEDs**: Indicate various states and operational statuses.
- **Multi-Colour LED**: Indicates the stability of the fan speed.  

---

## Display Functionality  

| **Mode**                     | **7-Segment Display**                    | **LCD Screen (Line 1)**       | **LCD Screen (Line 2)**     |  
|------------------------------|------------------------------------------|--------------------------------|-----------------------------|  
| Open Loop Control            | Duty cycle (%)                          | Time delta                    | Current fan speed           |  
| Closed Loop Fan Speed Control| Percentage error (target vs. current)   | Target RPM                    | Current fan speed           |  
| Closed Loop Temperature Control | Temperature (°C)                      | Target temperature            | Current fan speed           |  

---

## Setup  

- Connect the extension board to the left set of header pins.
- Connect all IOs as labelled below.
- Setup the circuit as shown below
- Using a USB Mini B, upload the supported .bin to the development board to program it.
- Connect a 12V supply to the power connectors on the extension board
- Connect the fan to the board.
- Power the development board and fan.
- The program should start automatically in the Open Loop Mode. 

---

## Usage  

1. **Power the board** and ensure all components are connected.  
2. Use the **button** to switch between modes.  
3. Adjust fan parameters as described:  
   - Use the rotary encoder for duty cycle or target RPM adjustments (depending on the mode).  
4. Monitor the **7-segment display** and **LCD screen** for real-time feedback.  

### Pin Connections Overview

#### LCD Pin Connections

| **Pin Value** | **Device Pin** | **Board Pin**       |
|---------------|----------------|---------------------|
| VSS           | 1              | GND                 |
| VDD           | 2              | U5V                 |
| VO            | 3              | 460 Ohm Potentiometer+ GND       |
| RS            | 4              | PA5                 |
| R/W           | 5              | AGND                |
| E             | 6              | PA6                 |
| DB0           | 7              | PA7                 |
| DB1           | 8              | PB6                 |
| DB2           | 9              | PC7                 |
| DB3           | 10             | PA9                 |
| DB4           | 11             | PA8                 |
| DB5           | 12             | PB10                |
| DB6           | 13             | PB4                 |
| DB7           | 14             | PB5                 |
| A/VEE         | 15             | N/C                 |
| K             | 16             | N/C                 |

#### 7-Segment Display Pin Connections

| **Pin Value** | **Device Pin** | **Board Pin** |
|---------------|------------|------------|
| a             | 16         | PB1        |
| b             | 15         | PB2        |
| c             | 3          | PB11       |
| d             | 2          | PB12       |
| e             | 1          | PA11       |
| f             | 18         | PA12       |
| g             | 17         | PC5        |
| Digit No. 1   | 14         | PC8        |
| a             | 11         | PB1        |
| b             | 10         | PB2        |
| c             | 8          | PB11       |
| d             | 6          | PB12       |
| e             | 5          | PA11       |
| f             | 12         | PA12       |
| g             | 7          | PC5        |
| Digit No. 2   | 13         | PC6        |

#### Temperature Sensor Pin Connections

> **Note**: A pull-up resistor is required on both the **SDA** and **SCLK** lines.

| **Pin Value** | **Device Pin** | **Board Pin** |
|---------------|------------|------------|
| NC            | 1          | NC         |
| SDA           | 2          | PB9        |
| GND           | 3          | GND        |
| SCLK          | 4          | PB8        |
| VDD           | 5          | U5V        |

---

## Contact Us

If you have any questions, suggestions, or feedback, feel free to reach out to us:

- Email: [cjg75@bath.ac.uk](mailto:cjg75@bath.ac.uk)
- GitHub Issues: [GitHub Issues Page](https://github.com/Ac3CJ/Nucleo-Fan-Controller/issues)

---

## Authors

This project was developed by:

- **Conrad Gacay** - [Ac3CJ](https://github.com/Ac3CJ)

Feel free to reach out for any collaboration or questions!

---

## FAQ

### Q: The system doesn't start in Open Loop Mode.
A: Check the wiring connections and ensure the power supply is correct. The system should automatically start in Open Loop Mode upon power-up.

### Q: How do I adjust the fan speed in Closed Loop Fan Speed Mode?
A: Use the rotary encoder to set the target RPM in Closed Loop Fan Speed Mode.

### Q: I cannot see anything on the LCD Screen.
A: Change the resistance on the 460Ohm potentiometer and check the connections.

### Q: The fan is plugged in but is not spinning.
A: Ensure that the power supply is turned on and that there is a valid connection into the banana sockets on the extension board.

---

## License  

This project is licensed under the [MIT License](LICENSE).  

--- 
