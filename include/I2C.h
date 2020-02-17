#include <TinyWireS.h>

#ifndef TWI_RX_BUFFER_SIZE
#define TWI_RX_BUFFER_SIZE ( 16 )
#endif

class I2C {
    
    public: I2C();

    void handleReceivedData(uint8_t address, uint8_t data);
    void receiveEvent(uint8_t t_address);
    void stopCheck();
};

