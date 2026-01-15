#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArtnetWifi.h>
#include <FastLED.h>
#include "secrets.h"  // local variables
//#include "dummypixels.h"

// LED Strip
const int numLeds = 400; // Change if your setup has more or less LED's
const int numberOfChannels = numLeds * 3; // Total number of DMX channels you want to receive (1 led = 3 channels)
#define DATA_PIN 12 //The data pin that the WS2812 strips are connected to.
CRGB leds[numLeds];

// Artnet settings
ArtnetWifi artnet;
const int startUniverse = 0;

bool sendFrame = 1;
int previousDataLength = 0;
int frameNo = 0;

// connect to wifi – returns true if successful or false if not
boolean ConnectWifi(void)
{
  boolean state = true;
  int i = 0;

  WiFi.begin(ssid, password);
  Serial.println("### ARTNET ESP32 ###");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(i);
    Serial.print(" | ");
    Serial.println(WiFi.status());
    // Serial.print(".");
    if (i > 200){
      state = false;
      ESP.restart();
      break;
    }
    i++;
  }
  if (state){
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("");
    Serial.println("Connection failed.");
  }

  return state;
}

void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{
  printf("onDmxFrame #%u\tuniverse: %u | length: %u | sequence: %u | data: %u\n", frameNo, universe, length, sequence, &data);
  sendFrame = 1;
  static uint8_t hue = 0;
  // set brightness of the whole strip 
  if (universe == 15)
  {
    FastLED.setBrightness(data[0]);
  }
  // read universe and put into the right part of the display buffer
  // using length/3 because 3 values define r/g/b of one pixel
  for (int i = 0; i < length / 3; i++)
  {
    //int led = i + (universe - startUniverse) * (previousDataLength / 3);

    // half circle line length 134
    int led = i + (universe - startUniverse) * 134;
    
    //Serial.println(printf("numleds %i %i \n", led, numLeds));
    if (led < numLeds)
    {
      leds[i] = CHSV(hue++, 255, 255);
     // leds[led] = CRGB(data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
      // Serial.printf("(%u %u %u)\n", leds[led].red, leds[led].green, leds[led].blue);
      
      // Serial.printf("(%u %u %u)\n", data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);

//      if (data[i * 3] != 0 || data[i * 3 + 1] != 0 || data[i * 3 + 2] != 0) {
//        Serial.print(printf("(%u %u %u)\n", data[i * 3], data[i * 3 + 1], data[i * 3 + 2]));
//      }
    }
  }
  previousDataLength = length;     
  FastLED.show();
  frameNo ++;
   delay(100);
}

void ScanWifi() {

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
      Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");  
}

void setup()
{
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  ScanWifi();

  ConnectWifi();
  artnet.begin();
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, numLeds);

  // onDmxFrame will execute every time a packet is received by the ESP32
  artnet.setArtDmxCallback(onDmxFrame);
}

void loop()
{
  // Serial.println("loop");
  // we call the read function inside the loop
  artnet.read();
}
