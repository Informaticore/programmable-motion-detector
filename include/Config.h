#include <EEPROM.h>
#include "constants.h"

class Config {
    public: Config() :
        m_mode(EEPROM.read(eeprom::MODE)),
        m_fade_enabled(EEPROM.read(eeprom::FADE_ENABLED)),
        m_fade_in_time(EEPROM.read(eeprom::FADEIN_TIME)),
        m_fade_out_time(EEPROM.read(eeprom::FADEOUT_TIME)),
        m_on_time(EEPROM.read(eeprom::ON_TIME)),
        m_strobo_frequency(EEPROM.read(eeprom::STROBO_FREQ))
        { }

    int getMode() const {
        return m_mode;
    }

    void setMode(uint8_t t_mode) {
        m_mode = t_mode;
        EEPROM.put(eeprom::MODE, m_mode);
    }

    int isFadeEnabled() const {
        return m_fade_enabled == 0xff;
    }

    void setFadeEnabled(bool t_fade_enabled) {
        m_fade_enabled = t_fade_enabled ? 0xFF : 0x00;
        EEPROM.put(eeprom::FADE_ENABLED, m_fade_enabled);
    }

    int getFadeInTime() const {
        return m_fade_in_time;
    }

    void setFadeInTime(uint8_t t_fade_in_time) {
        m_fade_in_time = t_fade_in_time;
        EEPROM.put(eeprom::FADEIN_TIME, m_fade_in_time);
    }

    int getFadeOutTime() const {
        return m_fade_out_time;
    }

    void setFadeOutTime(uint8_t t_fade_out_time) {
        m_fade_out_time = t_fade_out_time;
        EEPROM.put(eeprom::FADEIN_TIME, m_fade_out_time);
    }

    int getOnTime() const {
        return m_on_time;
    }

    void setOnTime(uint8_t t_on_time) {
        m_on_time = t_on_time;
        EEPROM.put(eeprom::ON_TIME, m_on_time);
    }

    int getStroboFrequency() const {
        return m_strobo_frequency;
    }

    void setStroboFrequency(uint8_t t_strobo_freq) {
        m_strobo_frequency = t_strobo_freq;
        EEPROM.put(eeprom::STROBO_FREQ, m_strobo_frequency);
    }

    private: 
        uint8_t m_mode;
        uint8_t m_fade_enabled;
        uint8_t m_fade_in_time;
        uint8_t m_fade_out_time;
        uint8_t m_on_time;
        uint8_t m_strobo_frequency;

};