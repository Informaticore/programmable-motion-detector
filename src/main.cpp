#include <Arduino.h>
#include <avr/io.h>
#include "I2C.h"
#include "Fader.h"

Fader fade;
I2C i2c;

int m_state = state::OFF;
unsigned long m_sensedMillis = 0;
unsigned long m_onTime = 5000;
unsigned long m_currentMillis = 0;

void fadeIt(int t_direction){
  if(!fade.isRunning()){
    fade.fade(t_direction);
  }

  bool done = fade.update();
  if(done){
    m_state = t_direction == direction::IN ? state::ON : state::OFF;
  }
}

void receiveEvent(uint8_t t_byte_count){
  i2c.receiveEvent(t_byte_count);
}

void setup() {
  TinyWireS.begin(i2creg::I2C_SLAVE_ADDRESS);
  TinyWireS.onReceive(receiveEvent);

  pinMode(pin::LEDPIN, OUTPUT);
  digitalWrite(pin::LEDPIN, LOW);
  pinMode(pin::SENSPIN, INPUT);
}

void checkSensPin(){
  if(digitalRead(pin::SENSPIN) == HIGH){
    m_sensedMillis = millis();
    if(m_state == state::OFF){
      m_state = state::FADE_IN;   
    }
  }
}

void loop() {
  i2c.stopCheck();
  checkSensPin();  
  
  switch(m_state){
    case state::FADE_IN:
      fadeIt(direction::IN);
      break;
    case state::FADE_OUT:
      fadeIt(direction::OUT);
      break;
    case state::ON:
      m_currentMillis = millis();
      if (m_currentMillis - m_sensedMillis >= m_onTime){
        m_state = state::FADE_OUT;
      }
      break;
    case state::OFF:
      break;
  }
}