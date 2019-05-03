int threshold = 40;
bool touch1detected = false;
bool touch2detected = false;
bool touch3detected = false;
bool touch4detected = false;
bool touch5detected = false;

void gotTouch1(){
 touch1detected = true;
}

void gotTouch2(){
 touch2detected = true;
}

void gotTouch3(){
 touch3detected = true;
}

void gotTouch4(){
 touch4detected = true;
}

void gotTouch5(){
 touch5detected = true;
}

void setup() {
  Serial.begin(115200);
  touchAttachInterrupt(T4, gotTouch1, threshold);
  touchAttachInterrupt(T6, gotTouch2, threshold);
  touchAttachInterrupt(T3, gotTouch3, threshold);
  touchAttachInterrupt(T7, gotTouch4, threshold);
  touchAttachInterrupt(T2, gotTouch5, threshold);
  pinMode(21, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  if (touch1detected){
    touch1detected = false;
    digitalWrite(18, HIGH); //left mustache
    delay(200);
    digitalWrite(18, LOW);
  }

  if (touch2detected){
    touch2detected = false;
    digitalWrite(16, HIGH); //right eye
  }

  if (touch3detected){
    touch3detected = false;
    digitalWrite(19, HIGH); //left eye
    
  }

  if (touch4detected){
    touch4detected = false;
    digitalWrite(5, HIGH); //right mustache
    
  }

  if (touch5detected){
    touch5detected = false;
    digitalWrite(17, HIGH); //right ear
    digitalWrite(21, HIGH); //left ear
  }
}
