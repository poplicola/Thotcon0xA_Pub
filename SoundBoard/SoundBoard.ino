#include "SoundData.h";
#include "XT_DAC_Audio.h";

XT_DAC_Audio_Class DacAudio(26,0); 

XT_Wav_Class soundTrombone(trombone); 
XT_Wav_Class soundHorn(airhorn);  
XT_Wav_Class soundDixie(dixie);                       
                                      
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
}

void loop() {
  DacAudio.FillBuffer();
  if (touch1detected){
    touch1detected = false;
    DacAudio.Play(&soundHorn);
    delay(200);
  }

  if (touch2detected){
    delay(200);
    DacAudio.FillBuffer();
    touch2detected = false;
    soundTrombone.Speed=2;
    DacAudio.Play(&soundTrombone);
    delay(200);
  }
 
  if (touch3detected){
    delay(200);
    DacAudio.FillBuffer();
    touch3detected = false;  
    soundDixie.Speed=2;
    DacAudio.Play(&soundDixie);
    delay(200);
  }

}
