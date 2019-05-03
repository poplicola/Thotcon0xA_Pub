# Examples for Thotcon 0xA Badge

## Introduction
The Thotcon 0xA badge runs off the Sparkfun ESP32 Thingdev board. Sparkfun has an excellent hookup guide [over on their website](https://learn.sparkfun.com/tutorials/esp32-thing-hookup-guide#introduction).

Some quick notes about pins on the 0xA badge:
* The touch pads for the device are on  t4, 6, 3, 7, 2. These are, respectively, right, up, left, down, and select.
* LEDS: 21, 19, 18, 17, 16, 5. These are, respectively, left ear, left eye, left mustache, right ear, right eye, right mustache.
* Speaker: 26
* Mic Pin: 25
* Mic_clock: 23
* Mic_ws: 22

## Getting Started with the Badge
1. Download/Install [Arduino](https://www.arduino.cc/)
2. Install [ESP32 board](https://github.com/espressif/arduino-esp32#installation-instructions) on Arduino platform (recommendation is to follow instructions under "Instructions for Boards Manager")

## LEDs (Hello World)
There are six backlit LEDs on the Thotcon 0xA badge. An example of how to activate these LEDs and utilize them is located in the LEDs directory of this GitHub.

## SoundBoard
The sound board maps five sounds to the five capacitive touch pads on the badge. The SoundBoard utilizes the audio library [XT_DAC_AUDIO](https://www.xtronical.com/the-dacaudio-library-download-and-installation/). Make sure this is included in any project that utilizes the speaker. Example code for this is located in in the SoundBoard directory.

Also note that all audio files must be converted before being uploaded to the badge. A brief explanation of how to convert audio for the badge follows.

### Converting Audio for the Badge
1. Download [Audacity](https://sourceforge.net/projects/audacity/)
2. Download a hex editor (suggestions for [Mac](https://ridiculousfish.com/hexfiend/), [Linux](https://github.com/bwrsandman/Bless), and [Windows](https://mh-nexus.de/en/hxd/))
3. Open file in Audacity and convert to wav by choosing the appropriate settings (instructions [here](https://www.xtronical.com/basics/audio/dacs-for-sound/playing-wav-files/))
4. Open file in hex editor and copy/paste into a txt file. Save
5. Open txt file (in vi or otherwise) and run regex command: `%s/ /,0x/gi`
6. After running command, make sure to additionally add 0x to the beginning of the first hex value in the file.
7. Get the size of array (one easy way to do this is by doing an "edit>find" on 0x). There is likely a smarter way to do these last three steps, but I don't have the time.
8. Save, copy text, and paste into an array into Arduino in a header file (example uses SoundData.h). Array container works thusly: const unsigned char StarWarsWav[SIZE_OF_ARRAY] = { YOUR_ARRAY };

## Audio Streaming
The Thotcon 0xA badge comes with a microphone that allows for streaming audio. An example of how to utilize this can be found in the AudioStreaming directory. Note that the 0xA badge has its own special driver for the microphone (located in the microphone_driver file). This must be included in any project that uses the mic.

On the server side, run this command in Terminal `nc -nlvp 4444 | aplay -b 16000 -f S32LE`

## Recognition
We relied heavily on this website for speaker audio, including the library that its owner created:
* https://www.xtronical.com

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

"_History_ repeats itself, first as tragedy, second as farce." - Karl Marx