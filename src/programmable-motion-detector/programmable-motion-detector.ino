int sensState;
int motionDetected = false;

int outPin = 1;
int sensPin = 2;

int interval = 30000;
int sensedMillis = 0;
int currentMillis = 0;

void setup() {
  pinMode(sensPin, INPUT);
  digitalWrite(sensPin, LOW);
  pinMode(outPin, OUTPUT);
}

void loop() {
  currentMillis = millis();
  sensState = digitalRead(sensPin);
  if(sensState == HIGH){
    sensedMillis = millis();
    if(!motionDetected){
      motionDetected = true;
      fadeIn();
    }
  } else {
    if(motionDetected && (currentMillis - sensedMillis >= interval)){
      fadeOut();
      motionDetected = false;
    }
  }
  delay(10);
}

void fadeIn(){
  for(int i = 0; i <= 255; i++){
    analogWrite(outPin, i);
    delay(10);
  }
}

void fadeOut(){
  for(int i = 255; i >= 0; i--){
    analogWrite(outPin, i);
    delay(10);
  }
}
