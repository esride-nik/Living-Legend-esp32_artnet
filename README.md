# SnipDrop: Bringing the Artnet info to the virtual pixels of SnipSign 2.0

Qlc+ sends pixel information according to how the device is defined. 3 values define r/g/b of one pixel. We need to map the image pixels to our actual LEDs, because they are not arranged in lines.

## Reason for deprecation
This was a technical spike to try out dividing the LED sign into a matrix of rows and columns.
=> This is the project I went live with: https://github.com/pnolle/SnipDrop_Esp32Wifi

## Motivaton
http://snippetupperlaser.com


## Dummy: Half Circle

# Pixel distribution

Incoming image pixels are X and Y. The numbering comes from a random matrix drawn with Matlab (https://github.com/pnolle/write_numbers_in_circle).

| X | Y | Numbers |
|---|---|---|
| 11 | 1 | 120,119,118,117,121,122,123 |
| 12 | 1 | 116,115,114,113,124,125,126,127 |
| 13 | 1 | 112,111,110,109,128,129,130,131,132 |
| 14 | 1 | 108,107,106,105 |
| 14 | 2 | 133,134,135,136 |
| 15 | 1 | 104,103 |
| 15 | 2 | 102,101,127,128,192,140 |
| 16 | 2 | 100,99,98,87,141 |
| 16 | 3 | 96, 142,143,144,145 |
| 17 | 3 | 95,94,93,92,91,146,147,148 |
| 17 | 4 | 90 |
| 18 | 3 | 149,150 |
| 18 | 4 | 90,89,88,87,86,151,152,153 |
| 19 | 4 | 154,155,156,157 |
| 19 | 5 | 85,84,83,82,81,158 |
| 20 | 5 | 80,79,78,159,160,161,162,163 |
| 20 | 6 | 77,76 |
| 21 | 5 | 164,165,166,167 |
| 21 | 6 | 75,74,73,72 |
| 22 | 6 | 168,169,170,171,71,70,69,68 |
| 23 | 6 | 172,173,174,175,67,66,65,64 |
| 24 | 6 | 176,177,178,179,63,62,61 |
| 25 | 6 | 180,181,182,183,60,59,58,57 |
| 26 | 6 | 184,185,186,187,188,56,55,54,53 |
| 27 | 6 | 189,190,191,192,52,51,50,49 |
| 28 | 5 | 193,194,195,196 |
| 28 | 6 | 48,47,46,45 |
| 29 | 5 | 197,198,199,200,201,42,41,40 |
| 29 | 6 | 44,43 |
| 30 | 4 | 203,204,205,206 |
| 30 | 5 | 202,39,38,37,36 |
| 30 | 4 | 207,208,35,34,33,32,31 |
| 30 | 3 | 209,210,211 |
| 31 | 4 | 30 |
| 31 | 3 | 212,213,21,29,28,27,26,25 |
| 31 | 2 | 215,216,217,218 |
| 32 | 2 | 219,24,23,22,21,20 |
| 32 | 1 | 220,221,222,223,19,18 |
| 32 | 0 | 224,225,226,227 |
| 33 | 1 | 17,16 |
| 33 | 0 | 228,15,14,13,12 |
| 33 | -1 | 229,230,231,232,11,10,9,8 |
| 33 | -2 | 233,234,235,236,7,6,5,4 |
| 33 | -3 | 237,238,239,240,3,2,1 |
