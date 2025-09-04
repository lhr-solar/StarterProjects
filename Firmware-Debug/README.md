# Solar Embedded Firmware Starter Project

The goal of this project is to teach you to write a bit of embedded firmware to output some text to your serial console. 

First, follow these [installation instructions](https://lhr-solar.github.io/Embedded-Sharepoint/Installation/) to get your environment set up for embedded development. Make sure you clone the Embedded-Sharepoint.

A few prerequisites:
- Mess around in your Linux shell. Here's a [basic list of commands](https://www.w3schools.com/bash/bash_commands.php). We'll be using this to compile and flash code.

## Questions

### What's an embedded?

An embedded system just refers to a circuit board with a microcontroller made for a specific purpose.

### What's a firmware?

Firmware refers to code that is run at a low level.

### What's a UART/USART?

UART (universal asynchronous receive/transmit) and USART (universal synchronous/asynchronous receive/transmit) are two protocols. A protocol is simply a defined way to communicate some data across wires. Both of these protocols have a transmit (TX) wire and a receive (RX) wire. USART has an optional clock wire (it's "synchronous" mode), but this is typically for a faster data transfer speed, so we'll only use asynchronous mode for right now.

UART enables device-to-device communication by connecting the transmit line of one device to the receive line of another. See [this article](https://www.analog.com/en/resources/analog-dialogue/articles/uart-a-hardware-communication-protocol.html) for more information on UART.

### What's a serial? What's a peripheral?

Serial communications typically refer to a protocol like UART (Universal Asynchronous Receive/Transmit). It's a way to send bits over a wire. Your computer can read these bits when they're translated to USB (we have a USB<->UART chip on most of our boards).

A peripheral is a unit of hardware that serves a specific purpose. Typically, these units are built into the microcontroller. For example, a UART peripheral allows the user to configure it to spit out the UART protocol, same for I2C, SPI, CAN (these are all different protocols we use on the car).

### What's an STM32 Nucleo?

The STM32 series of microcontrollers are what we use on all of our circuit boards. An STM32 Nucleo is a development board, which means before your cool little circuit board comes in you can test-run code on there. It's kind of like an Arduino, with all of the pins of the microcontroller broken out to headers (the little spiky metal bits).

### What's a microcontroller?

Look at the Nucleo you should have in your hands. The big black square in the middle is a microcontroller. A microcontroller is a chip that has memory and can run code. You can think of it as a small computer on a single chip.

### What's a pinout?

See how your Nucleo has small little pieces of metal surrounding the black square? These are the pins of the microcontroller. There is circuitry connecting them to the large spiky pieces of metal on the Nucleo. The specific pins that are "exposed" to the outside world is called a pinout.

### What's a GPIO?

Every pin on your microcontroller is considered a "general purpose input/output" pin. By configuring the GPIO peripheral, you can set up certain pins with specific "alternate functions" that allow other peripherals to use the pin (in this case, UART/USART).

### What's a STM32 HAL?

The Hardware Abstraction Layer is a library of code that we use to interface with different peripherals, provided to us by STMicroelectronics (the same company that makes our microcontrollers).

### What's a BSP?

The BSP is a library we've developed on top of the HAL to facilitate interrupt and queue-based transactions of data. If the HAL lets you transmit one byte at a time, the BSP lets you queue up transmits to be sent by a interrupt.

### What's a STM32CubeMX?

[STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html) is a software we use to generate initializations and starter code for some of our peripherals. You can select a chip and configure for the proper pins you want to use for, and then spit out proper initialization code. *Please download it.*

## Starter Project

You should have been given a Nucleo with a specific part number, e.g. NUCLEO-F446RE. This part number should be written on the board. Google "<part-number> user manual" and open the user manual for your Nucleo.

### Nucleo User Manual

1. Scroll down to the "Hardware Layout and Configuration" section and find a section called "UART communication"/"USART communication". This should have a paragraph related to which pins the UART/USART interface is on (for the NUCLEO-F446RE, it's on PA2/PA3) and the UART/USART peripheral number (for the NUCLEO-F446RE, it's USART2).
2. Next, scroll to the "Extension connectors" section and find your specific Nucleo's diagram. These diagrams indicate which pins on the microcontroller are connected to which pins on the "Morpho connector" (a **pinout**).

Your microcontroller has a specific part number as well. You should be able to figure this out with some investigation. (hint: check the user manual and note the suffix after "NUCLEO-"). The part number should start with "STM32".

Next, we're going to create our test file.

### Test File Creation

Notice that there is a Src directory in the Firmware-Debug folder in this starter project. This is going to store your "source code", or the files that contain actual lines of code your microcontroller will run. 

Also notice that the Embedded-Sharepoint exists in this repository already. A repository inside a repository is referred to as a "submodule".

Read through the file called Makefile. You're not going to understand most of this right now, but you can think of a Makefile as a script that compiles your code ([it's a little more complex than that](makefiletutorial.com)). Notice the variables PROJECT_C_SOURCES, PROJECT_C_INCLUDES, PROJECT_BUILD_DIR, and BUILD_MAKEFILE_DIR. These are four variables that specify where the source files, the header files, the build directory, and the main makefile directory. These variables are passed to the main makefile located at `Embedded-Sharepoint/Makefile`, which does the heavy lifting of building your code.

Create a file called `main.c` in the Src directory. Add the following lines to your code:
```
int main(){
  while(1){
  }
}
```
```
```

The function "main" is always the entry point of your program. We add an infinite while-loop because in an embedded system, there's never an "end point" for your code since the entire time it is on, it should be running something.

Now to compile, run the following command:
`make PROJECT_TARGET=<microcontroller-part-number>`

The microcontroller part number should be the one you found for your Nucleo in the previous section, lowercase (e.g. stm32f446ret). It should be the exact part number.

If successful, you should see a bunch of compile commands (CC <source file> -> <object file>) executed followed by a final linking step (LD <final .elf file>). 

Open up STM32CubeMX for this next section.

### STM32CubeMX Initialization Code Generation

1. Click "Access to MCU Selector". Find your microcontroller part number in the provided table. Double click it and a new screen should pop up with a microcontroller on the right side.

2. Look on the left and you will see a sidebar of dropdowns (System Core, Analog, Timers, etc.). Open up the Connectivity dropdown and select the appropriate UART or USART peripheral depending on the number you found before.

3. Click the dropdown in the middle and select "Asynchronous". This will enable the UART/USART peripheral in asynchronous mode. The pins on the microcontroller that this peripheral is connected to are highlighted in green on the right.

4. See and note the parameter settings at the bottom. The important ones are the baud rate (115200 bits per second), the word length (8 bits), parity (none) and the number of stop bits (1).

5. Click the project manager tab at the top. 
- Project location: browse for a directory that you want to clone the code into (separate from your Embedded Sharepoint clone location). 
- Application structure: select basic 
- Toolchain/IDE: select Makefile

6. Click "Generate Code" at the top. If a "missing firmware package" error appears, ignore it and hit continue. Open the folder that the code is generated into.

7. There should be a file called "Src/stm32f4xx_hal_msp.c". Open this file in your text editor of choice.

8. Find the method `void HAL_UART_MspInit(UART_HandleTypeDef* huart)`. I'll explain a few lines of this method that I generated for the NUCLEO-F446RE.

- `GPIO_InitTypeDef GPIO_InitStruct = {0};` -- initializes an empty structure of type GPIO_InitTypeDef, which contains configuration parameters for GPIO initialization.

- `__HAL_RCC_GPIOA_CLK_ENABLE();` -- enables the clock for the GPIO peripheral on port A.

- GPIO Initialization:
```
```
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
```
```
  
  This configures GPIO pins 2 and 3 on port A for alternate function (AF) 7, which is USART2. It also sets the pullup/pulldown resistor to NOPULL and the speed to VERY_HIGH.

9. Copy the GPIO_InitStruct, the GPIO clock enable, and all the GPIO configuration options listed above from your generated code to your test file in a new function called `void HAL_UART_MspGPIOInit(UART_HandleTypeDef *huart)` in your `main.c`. Note the GPIO in the function name.
- *Editor's note: what's essentially being done here is called a weak function override. In Embedded-Sharepoint/bsp/Src/UART.c, you'll see a function of the same name with the prefix __weak. This function has some default behavior that we are meant to redefine, in this case to initialize the GPIO pins for the UART peripheral. Since UART.c is a generic UART driver, it has to support all different pin combinations that the user might need, which is why this MspGPIOInit is necessary as an initialization step.*

10. If you try compiling at this point with `make`, you should get an error regarding `UART_HandleTypeDef`. This is because `main.c` is not aware about the existence of a structure called "UART_HandleTypeDef" because it does not know where it is defined. Thus, we're going to need to *include* the file that contains the definition of UART_HandleTypeDef, which is defined in the HAL. Add `#include "UART.h"` to the top of the file.
- *Editor's note: the include directive tells the compiler to paste the contents of the specified header file into the current file. This means all definitions made in a header file (function definitions, structure definitions, type definitions, enums) will be pasted before the usage of those definitions, so UART_HandleTypeDef can now be used.*

Now that we're done with initialization, we'll move on to the main loop of sending bytes over UART.

## Main Loop and BSP UART


