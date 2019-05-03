#include <Arduino.h>
#include <WiFi.h>
#include <driver/adc.h>
#include <driver/i2s.h>

#define AUDIO_BUFFER_MAX 200

uint8_t audioBuffer[AUDIO_BUFFER_MAX];
uint32_t transmitBuffer[AUDIO_BUFFER_MAX];
uint32_t bufferPointer = 0;

const char* ssid     = "YourWiFi";
const char* password = "YourPassword";
const char* host     = "ServerIP";

bool transmitNow = false;
int read_raw;

WiFiClient client;

hw_timer_t * timer = NULL; // our timer
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED; 

const i2s_port_t I2S_PORT = I2S_NUM_0;

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("MY IP address: ");
  Serial.println(WiFi.localIP());
  
  const int port = 4444;
  while (!client.connect(host, port)) {
    Serial.println("connection failed");
    delay(1000);
  }

  Serial.println("connected to server");

  microphone_driver();

}

void loop() {
  int32_t sample = 0;
  for (uint8_t i=0; i< (AUDIO_BUFFER_MAX); i++)
  {
        int bytes_read = i2s_pop_sample(I2S_PORT, (char *)&sample, portMAX_DELAY); // no timeout
        if (bytes_read>0)
        {
           transmitBuffer[i] = sample;
           
        }
  }
 // if (bytes_read>0) { // checks if the buffer is full
    client.write((const uint8_t *)transmitBuffer,sizeof(transmitBuffer)); // sending the buffer to our server
  //}
}
