# stm32-esp
code to serial communicate between stm32 and esp


Connections:

    STM32 TX (e.g., PA2) --> ESP RX (e.g., GPIO3)
    STM32 RX (e.g., PA3) --> ESP TX (e.g., GPIO1)
    Common GND between STM32 and ESP



    STM32: Sends a message to the ESP and waits to receive a response.
    ESP: Receives the message from STM32, processes it, and sends a response back.
