# Living Legend
made with the ArcGIS Maps SDK for JavaScript, Node.js and ESP32.

---

Send the map legend to a RGB LED strip like [here](https://www.instagram.com/reel/CpglP7nA4MB)!

## This repo
Use this ESP32 firmware to receive data from ``artnet-http`` and put it on your LED strip via FastLED.

## Other repos needed to make sense of this

### artnet-http
You can use my fork of Dewb's [``artnet-http`` project](https://github.com/esride-nik/artnet-http) to run a small Node.js application on localhost that receives data from the map, transforms it into Artnet and sends it over to the ESP32.

### jssdk-artnet-webclient
This is the webmap with [logic for legend2LEDs](https://github.com/esride-nik/jssdk-artnet-webclient).
