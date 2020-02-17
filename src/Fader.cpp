#include "Fader.h"

void Fader::fade(int t_direction){
  m_running = true;
  m_direction = t_direction;
  m_lastSteppedMillis = millis();
  m_index = 0; //reset to 0 for next run
}

bool Fader::update(){
  m_currentMillis = millis();
  if(m_currentMillis - m_lastSteppedMillis >= m_fadeStep){
    m_lastSteppedMillis = millis();
    m_index++;
  }

  if(m_index <= m_max){
    analogWrite(pin::LEDPIN, m_direction == direction::IN ? m_index : m_max - m_index);
    return false;
  } else {
    m_running = false;
    return true;
  }
}
