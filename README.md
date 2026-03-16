# Arcadia_micro

An embedded game system developed on a PIC24 microcontroller, featuring joystick and button-based input, LCD output, and modular peripheral control in C.

## Overview

Arcadia_micro is a microcontroller-based interactive game project built in C for the PIC24 platform.  
The project integrates multiple hardware components, including a joystick, buttons, and an LCD display, to create a simple embedded gaming experience.

This project emphasizes:
- embedded C programming
- hardware-software integration
- real-time input handling
- LCD display control
- modular driver development

## Features

- Joystick-based directional input
- Button-based interaction
- LCD display output
- PIC24 initialization and peripheral setup
- Modularized source files for different hardware components

## Repository Structure

- `pic24_init.c`  
  Initializes the PIC24 microcontroller and configures core system settings.

- `JoyStick.c`  
  Handles joystick input reading and processing.

- `Button.c`  
  Manages button input and related control logic.

- `LCD.c`  
  Controls LCD display output and screen updates.

- `README.md`  
  Project documentation.

## Technologies Used

- C
- PIC24 microcontroller
- Embedded systems programming
- LCD interfacing
- Joystick and button input handling

## Project Goals

The goal of this project was to design and implement a small embedded game platform that demonstrates:
- real-time user input processing
- modular peripheral drivers
- interaction between hardware components and game logic
- embedded system design on a resource-constrained platform

## Team Contributions

This project was completed as a team project. Contributions included:
- hardware interface development
- joystick and button input integration
- LCD communication and display handling
- debugging and testing of embedded system behavior

## How to Use

1. Open the project in the appropriate PIC24 development environment.
2. Build and compile the source code.
3. Flash the program onto the PIC24 microcontroller.
4. Connect the required hardware components:
   - joystick
   - buttons
   - LCD display
5. Run the system and interact with the game through the input devices.

## Notes

This repository currently contains the core embedded source files for the project.  
Additional improvements may include:
- adding full game logic documentation
- including hardware schematics
- providing setup instructions for the development environment
- adding demo images or videos

## Future Improvements

- Add a full project diagram
- Include screenshots or hardware photos
- Expand documentation for each module
- Add build/setup details for reproducibility
