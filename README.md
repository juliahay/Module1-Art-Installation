# Art Installation!

This code is for a generative art installation using a ESP32 with a TTGO T-Dispaly. It was made in February 2024 for Professor Mark Santolucito's Creative Embedded Systems Course.

![](https://github.com/juliahay/Module1-Art-Installation/blob/main/images/intCourtroom.JPG)

The goal of my project is to create randomly generated scripts between two lawyers as made from a selection of different stereotypical lawyer phrases. To conserve battery power, the screen goes into deep sleep for one minute after each script runs.

## Materials
- ESP32 TTGO T-Display
- 220 mAh battery
- USB-C Cord

## How to Set Up
- Download the [Arduino IDE](https://www.arduino.cc/en/software)
- Connect the ESP32 with a USB-C Cable (Make sure the blue light on the board gets turned on. If it doesn't, try turing around how the USB-C Cable is plugged in)
- Under the `Boards Manager` tab, download the ESP32 board by expressif Systems (https://dl.espressif.com/dl/package_esp32_index.json)
- With the ESP32 plugged in, select the port connected to the device and assign it to the TTGO T1 board.
- Under `Tools`, set the `Upload Speed` to "115200" to avoid errors with uploading code to device.
- Under `Libraries`, download the "TFT_eSPI" library by Bodmer
- Find the folder on your CPU where Arduino libraries are stored and open the User_Setup_Select.h file in the TFT_eSPI library folder `Arduino/libraries/TFT_eSPI/User_Setup_Select.h`
  - Comment out the line `#include <User_Setup.h>`
  - Uncomment the line `#include <User_Setups/Setup25_TTGO_T_Display.h>`
- At this point, you should be able to upload the code onto your TTGO T-Display by simply pressing the `Upload` button. The code should compile and run.

## Further Documentation
To read the full blog post regarding this installation, visit [here](https://juliahay.github.io/CES-portfolio/module1/module1.html)
