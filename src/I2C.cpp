#include "I2C.h"
#include "constants.h"

volatile uint8_t reg_position;
volatile uint8_t data;

I2C::I2C() {
    
}

void I2C::receiveEvent(uint8_t t_byte_count){
    if (t_byte_count < 1){ return; }
    if (t_byte_count > 2){ return; }
    if (t_byte_count > TWI_RX_BUFFER_SIZE) { return; }

    reg_position = TinyWireS.receive();
    t_byte_count--;
    if (!t_byte_count){
        // This write was only to set the buffer for next read
        return;
    }

    data = TinyWireS.receive();
    handleReceivedData(reg_position, data);
}

void I2C::handleReceivedData(uint8_t address, uint8_t data) {
    switch (address) {
    case i2creg::REG_FADE_ENABLED:
        
        break;
    
    default:
        break;
    }
}

void I2C::stopCheck(){
    TinyWireS_stop_check();
}