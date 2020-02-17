#include <Arduino.h>
#include <avr/io.h>
#include "constants.h"

class Fader {

  public: Fader():
    m_direction(-1),
    m_max(255),
    m_index(0),
    m_currentMillis(0),
    m_fadeStep(10),
    m_lastSteppedMillis(0),
    m_running(false)
    {}

  void fade(int t_direction);
  bool update();
  bool isRunning() const {
    return m_running;
  }

  private:
    int m_direction;
    int m_max;
    int m_index;
    unsigned long m_currentMillis;
    unsigned long m_fadeStep;
    unsigned long m_lastSteppedMillis;
    bool m_running;

};