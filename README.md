
# Singularity Lib


## Brief

What do I want to achieve with this?

- A set of interrupt driven fast communication drivers
    - UART
    - SPI
    - I2C
    - I2S    
- Handlers which send events
- A heirarchical event handler structure
    - LL Events bubble up to the driver handler
    - Driver handler emits events to user loops
- Sensible buffer usage, smart locking
- Integration with processing buffers, ring-buffers
- Integration with FreeRTOS
- Low memory usage
- Safe fail conditions
- Utilise DMA
- Asynchronous operation with async/sync interface
- Keep this a Library
- Cmake build files

- Specific to the current chip-set but later make portable

### Personal Goals

- Unit tests; could be hard with rtos 
- cleanest of code
- cleanest of gits
- architectural thinking
- embedded debugging practice
- showcase

### Notes below
