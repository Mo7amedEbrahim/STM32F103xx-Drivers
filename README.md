# STM32F103C8T6 Blue Pill Drivers
This repository contains a collection of drivers and libraries for the STM32F103C8T6 microcontroller board, commonly known as the Blue Pill. These drivers provide an abstraction layer for various peripherals and functionalities of the microcontroller, making it easier to develop applications and projects.

## Features
### GPIO driver:
Provides functions to configure and control GPIO pins.
### RCC driver:
Manages the Reset and Clock Control (RCC) peripheral for configuring system clocks.
### NVIC driver:
Handles Nested Vector Interrupt Controller (NVIC) for interrupt management.
### EXTI driver:
Supports External Interrupt (EXTI) functionality for GPIO interrupts.
### AFIO driver:
Manages Alternate Function I/O (AFIO) configuration for remapping pins.
### SysTick driver:
Provides a system tick timer for generating periodic interrupts.
### DMA driver:
Provides DMA transfer functions for efficient data transfers.
### USART driver: (SOON)
Supports UART communication with USART peripheral.
### SPI driver:   (SOON)
Allows SPI communication with SPI peripheral.
### I2C driver: (SOON)
Enables I2C communication using the I2C peripheral.
### Timers driver:  (SOON)
Supports various timer functionalities, such as PWM generation and input capture.

## Documentation (SOON)
For detailed documentation and usage examples, refer to the individual driver directories. Each driver directory contains a README file with specific instructions on how to use the driver, as well as code examples and API references.

## Contributing
Contributions to this repository are welcome. If you find any issues or have improvements to suggest, please feel free to submit a pull request. Make sure to follow the existing coding style and provide clear descriptions of your changes.

## License
This repository is licensed under the MIT License. You are free to use, modify, and distribute the code as per the terms of the license.

## Acknowledgments
The drivers in this repository are based on the STM32 HAL library and have been adapted for the STM32F103C8T6 microcontroller.
