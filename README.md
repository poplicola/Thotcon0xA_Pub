# Examples for Thotcon 0xA Badge

## Introduction
The Thotcon 0xA badge runs off the Sparkfun ESP32 Thingdev board. Sparkfun has an excellent hookup guide ]over on their website](https://learn.sparkfun.com/tutorials/esp32-thing-hookup-guide#introduction).

Some quick notes about pins on the 0xA badge:
* The touch pads for the device are on  t4, 6, 3, 7, 2
* LEDS: 21, 19, 18, 17, 16, 5 
* Speaker: 26
* Mic Pin: 25
* Mic_clock: 23
* Mic_ws: 22
//Jay to put in image that maps all of these to where they belong

## Getting Started with the Badge
1. Install Arduino
2. Install ESP32 board on Arduino platform
3. Get audio library and include in project

## LEDs (Hello World)
There are six backlit LEDs on the Thotcon 0xA badge. An example of how to activate these LEDs and utilize them is located in the NARF directory of this GitHub.

## SoundBoard
The sound board maps five sounds to the five capacitive touch pads on the badge. Example code for this is located in NARF

## Audio Streaming
The Thotcon 0xA badge comes with a microphone that allows for streaming audio. An example of how to utilize this can be found in NARF. Note that the 0xA badge has its own special driver for the microphone (located in the microphone_driver file). This must be included in any project that uses the mic.

Also note that all audio files must be converted before being uploaded to the badge. A brief explanation of how to convert audio for the badge follows.

### Converting Audio for the Badge

## Recognition
Microphone Code:
* How to do microphone driver init: https://github.com/maspetsberger/esp32-i2s-mems/blob/master/examples/InputSerialPlotter/InputSerialPlotter.ino

Speaker Code:
* Library for playing sound: https://www.xtronical.com/basics/audio/dacs-for-sound/playing-wav-files/

Audio Streaming:
* https://www.hackster.io/julianfschroeter/stream-your-audio-on-the-esp32-2e4661

ESP32 Radio:
* https://github.com/Edzelf/ESP32-Radio

Documentation
* Espressif documentation on using audio with their chip. Notable, they mention one main consideration being “Ethernet interface to obtain an audio data stream from the internet” https://docs.espressif.com/projects/esp-adf/en/latest/design-guide/project-design.html