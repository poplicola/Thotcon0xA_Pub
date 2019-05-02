#include "SoundData.h";
#include "Game_Audio.h";

Game_Audio_Class GameAudio(26,0); 

Game_Audio_Wav_Class soundHorn(airhorn);
Game_Audio_Wav_Class soundTrombone(trombone);   
//Game_Audio_Wav_Class soundDixie(dixie);                       
                                      
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
  if (touch1detected){
    touch1detected = false;
    GameAudio.PlayWav(&soundHorn, true, 1.0);
    delay(200);
  }

  if (touch2detected){
    touch2detected = false;
    GameAudio.PlayWav(&soundTrombone, true, 3.0);
    delay(200);
  }
  /*
  if (touch3detected){
    touch3detected = false;
    GameAudio.PlayWav(&soundDixie, true, 2.0);
    delay(200);
  }*/

}
