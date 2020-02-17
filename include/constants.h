namespace state{
    const int OFF       = 0;
    const int ON        = 1;
    const int FADE_IN   = 2;
    const int FADE_OUT  = 3;
    const int RESET     = 4; 
}

namespace eeprom {
    const int FADE_ENABLED  = 0x00;
    const int FADEIN_TIME   = 0x01;
    const int FADEOUT_TIME  = 0x02;
    const int ON_TIME       = 0x03;
    const int STROBO_FREQ   = 0x04;
    const int MODE          = 0x05; 
}

/* namespace configDefaults {
    const int FADE_ENABLED  = 0xFF;
    const int FADEIN_TIME   = 10;
    const int FADEOUT_TIME  = 10;
    const int ON_TIME       = 30;
    const int STROBO_FREQ   = 10;
    const int MODE          = 0xFF; 
} */

namespace direction {
    const int IN    = 20;
    const int OUT   = 21;
}

namespace mode {
    const int NONE      = 0xFF;
    const int STROBO    = 0x01;
    const int BLINK     = 0x02;
    const int BROKEN    = 0x03;
    const int FIRE      = 0x03;
    const int ON        = 0x04;
    const int OFF       = 0x05; 
}

namespace pin {
    const int SENSPIN = 3;
    const int LEDPIN = 1;
}

namespace i2creg {
    const int I2C_SLAVE_ADDRESS = 0x42;
    const int REG_FADE_ENABLED  = 0x00;
    const int REG_FADEIN_TIME   = 0x01;
    const int REG_FADEOUT_TIME  = 0x02;
    const int REG_ON_TIME       = 0x03;
    const int REG_STROBO_FREQ   = 0x04;
    const int REG_MODE          = 0x05; 
}
