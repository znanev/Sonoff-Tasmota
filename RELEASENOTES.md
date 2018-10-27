## Migration Information
See [wiki migration path](https://github.com/arendst/Sonoff-Tasmota/wiki/Upgrade#migration-path) for instructions how to migrate to a major version. Pay attention to the following version breaks due to dynamic settings updates:

1. Migrate to **Sonoff-Tasmota 3.9.x**
2. Migrate to **Sonoff-Tasmota 4.x**
3. Migrate to **Sonoff-Tasmota 5.14**
4. Migrate to **Sonoff-Tasmota 6.x**

## Release notes
### Change in default initial configuration tool
Firmware binary **sonoff-classic.bin** supports **WifiManager, Wps and SmartConfig** for initial configuration. The default tool is **Wps**.

To save memory space all other binaries support **WifiManager only**.

See _changelog.ino how to enable them again.
- Define WIFI_CONFIG_TOOL now contains the default behaviour once a SSID has been configured.
- If no SSID is configured making a wifi connection impossible the new define WIFI_CONFIG_NO_SSID will be used.
- While define WIFI_CONFIG_NO_SSID is set to WIFI_WPSCONFIG in my_user_config.h the compiler will check for define USE_WPS and if not enabled WIFI_CONFIG_NO_SSID will default to WIFI_MANAGER using the webserver. If define USE_WEBSERVER is also not enabled WIFI_CONFIG_NO_SSID will default to WIFI_SMARTCONFIG. If define USE_SMARTCONFIG is also not enabled WIFI_CONFIG_NO_SSID will default to a new option WIFI_SERIAL allowing to enter wifi parameters to serial which is always possible.

## Provided Binary Downloads
The following binary downloads have been compiled with ESP8266/Arduino library version **2.3.0**

- **sonoff-minimal.bin** = The Minimal version allows intermediate OTA uploads to support larger versions and does NOT change any persistent parameter. This version **should NOT be used for initial installation**.
- **sonoff-classic.bin** = The Classic version allows **initial installation** using either WifiManager, Wps or SmartConfig.
- **sonoff.bin** = The Sonoff version without Wps and SmartConfig configuration but adds more sensors.
- **sonoff-BG.bin** to **sonoff-TW.bin** = The Sonoff version without Wps and SmartConfig configuration in different languages.
- **sonoff-sensors.bin** = The Sensors version without Wps and SmartConfig configuration but adds even more useful sensors.
- **sonoff-display.bin** = The Display version without Wps and SmartConfig configuration but adds display support.
- **sonoff-knx.bin** = The Knx version without Wps and SmartConfig configuration and some other features but adds KNX support.

See [Tasmota ESP/Arduino library version related issues](https://github.com/arendst/Sonoff-Tasmota/wiki/Theo's-Tasmota-Tips#20180523---relation-tasmota-and-esp8266arduino-core-version) why these files are still released using ESP/Arduino library version v2.3.0.

### Available Features and Sensors

| Feature or Sensor              | minimal | classic | sonoff | knx  | sensors | Remarks
|--------------------------------|---------|---------|--------|------|---------|--------
| ESP/Arduino lib v2.3.0         | 344k    | 485k    | 491k   | 510k | 516k    |
| ESP/Arduino lib v2.4.2         | 363k    | 499k    | 509k   | 526k | 532k    | No sleep
|                                |   |   |   |   |   |
| MY_LANGUAGE en-GB              | x | x | x | x | x |
| USE_WPS                        | - | x | - | - | - | WPS
| USE_SMARTCONFIG                | - | x | - | - | - | SmartConfig
| USE_ARDUINO_OTA                | - | - | - | - | - |
| MQTT_LIBRARY_TYPE PUBSUBCLIENT | x | x | x | x | x |
| USE_DOMOTICZ                   | - | x | x | x | x |
| USE_HOME_ASSISTANT             | - | x | x | x | x |
| USE_MQTT_TLS                   | - | - | - | - | - |
| USE_KNX                        | - | - | - | x | - |
| USE_WEBSERVER                  | x | x | x | x | x | WifiManager
| USE_EMULATION                  | - | x | x | - | x |
| USE_DISCOVERY                  | - | x | x | x | x |
| WEBSERVER_ADVERTISE            | - | x | x | x | x |
| MQTT_HOST_DISCOVERY            | - | x | x | x | x |
| USE_TIMERS                     | - | - | x | x | x |
| USE_TIMERS_WEB                 | - | - | x | x | x |
| USE_SUNRISE                    | - | - | x | x | x |
| USE_RULES                      | - | - | x | x | x |
|                                |   |   |   |   |   |
| USE_ADC_VCC                    | x | x | x | x | - |
| USE_DS18B20                    | - | - | - | - | - | Single sensor
| USE_DS18x20                    | - | x | x | x | x | Multiple sensors
| USE_DS18x20_LEGACY             | - | - | - | - | - | Multiple sensors
|                                |   |   |   |   |   |
| Feature or Sensor              | minimal | classic | sonoff | knx  | sensors |
| USE_I2C                        | - | - | x | x | x |
| USE_SHT                        | - | - | x | x | x |
| USE_HTU                        | - | - | x | x | x |
| USE_BMP                        | - | - | x | x | x |
| USE_BME680                     | - | - | - | - | x |
| USE_BH1750                     | - | - | x | x | x |
| USE_VEML6070                   | - | - | - | - | x |
| USE_ADS1115                    | - | - | - | - | x |
| USE_ADS1115_I2CDEV             | - | - | - | - | - |
| USE_INA219                     | - | - | - | - | x |
| USE_SHT3X                      | - | - | x | x | x |
| USE_TSL2561                    | - | - | - | - | x |
| USE_MGS                        | - | - | - | - | x |
| USE_SGP30                      | - | - | x | x | x |
| USE_SI1145                     | - | - | - | - | x |
| USE_LM75AD                     | - | - | x | x | x |
| USE_APDS9960                   | - | - | - | - | - |
| USE_MCP230xx                   | - | - | - | - | - |
| USE_PCA9685                    | - | - | - | - | - |
| USE_MPR121                     | - | - | - | - | - |
| USE_CCS811                     | - | - | - | - | - |
| USE_MPU6050                    | - | - | - | - | - |
| USE_DS3231                     | - | - | - | - | - |
|                                |   |   |   |   |   |
| Feature or Sensor              | minimal | classic | sonoff | knx  | sensors |
| USE_SPI                        | - | - | - | - | - |
| USE_MHZ19                      | - | - | x | x | x |
| USE_SENSEAIR                   | - | - | x | x | x |
| USE_PMS5003                    | - | - | x | x | x |
| USE_NOVA_SDS                   | - | - | x | x | x |
| USE_PZEM004T                   | - | - | x | x | x |
| USE_PZEM_AC                    | - | - | x | x | x |
| USE_PZEM_DC                    | - | - | x | x | x |
| USE_MCP39F501                  | - | - | x | x | x |
| USE_SERIAL_BRIDGE              | - | - | x | x | x |
| USE_SDM120                     | - | - | - | - | x |
| USE_SDM630                     | - | - | - | - | x |
| USE_MP3_PLAYER                 | - | - | - | - | - |
| USE_IR_REMOTE                  | - | - | x | x | x |
| USE_IR_HVAC                    | - | - | - | - | x |
| USE_IR_RECEIVE                 | - | - | x | x | x |
| USE_WS2812                     | - | x | x | x | x |
| USE_WS2812_DMA                 | - | - | - | - | - |
| USE_ARILUX_RF                  | - | - | x | x | x |
| USE_SR04                       | - | - | x | x | x |
| USE_TM1638                     | - | - | - | - | - |
| USE_HX711                      | - | - | x | x | x |
| USE_RF_FLASH                   | - | - | x | x | x |
| USE_TUYA_DIMMER                | - | - | x | x | x |
| USE_TX20_WIND_SENSOR           | - | - | x | x | x |
| USE_RC_SWITCH                  | - | - | x | x | x |
| USE_DISPLAY                    | - | - | - | - | - |

## Changelog
Version 6.3.0 soon
 * Change web Configure Module GPIO drop down list order for better readability
 * Change status JSON message providing more switch and retain information
 * Change xsns_17_senseair.ino to use TasmotaModbus library
 * Change MCP230xx driver
 * Change PubSubClient Mqtt library to non-blocking EspEasy version
 * Change energy monitoring using energy sensor driver modules
 * Change Webserver page handler for easier extension (thx to Adrian Scillato)
 * Change pinmode for no-pullup defined switches to pullup when configured as switchmode PUSHBUTTON (=3 and up) (#3896)
 * Change default OTA Url to http://thehackbox.org/tasmota/release/sonoff.bin (#4170)
 * Remove support for MQTT Client esp-mqtt-arduino by #define MQTT_LIBRARY_TYPE MQTT_ESPMQTTARDUINO
 * Remove commands PowerCal, VoltageCal and CurrentCal as more functionality is provided by commands PowerSet, VoltageSet and CurrentSet
 * Remove restart after ntpserver change and force NTP re-sync (#3890)
 * Fix showing Period Power in energy threshold messages
 * Fix header file execution order by renaming user_config.h to my_user_config.h
 * Fix some TSL2561 driver issues (#3681)
 * Fix KNX PA exception. Regression from 6.2.1 buffer overflow caused by subStr() (#3700, #3710)
 * Fix setting and getting color temperature for Philips Hue emulation (#3733)
 * Fix ButtonRetain to not use default topic for clearing retain messages (#3737)
 * Fix syslog when emulation is selected (#2109, #3784)
 * Fix rule trigger POWER1#STATE execution after restart and SetOption0 is 0 (#3856)
 * Fix Home Assistant forced light discovery (#3908)
 * Fix invalid configuration restores and decode_config.py crc error when savedata = 0 (#3918)
 * Fix timer offset -00:00 causing 12:00 hour offset (#3923)
 * Fix I2CScan invalid JSON error message (#3925)
 * Fix exception when wrong Domoticz JSON message is received (#3963)
 * Fix Sonoff Bridge RfRaw receive (#4080, #4085)
 * Fix possible wifi connection error (#4044, #4083)
 * Fix invalid JSON floating point result from nan (Not a Number) and inf (Infinity) into null (#4147)
 * Fix rule mqtt#connected trigger when mqtt is disabled (#4149)
 * Add support for LCD, Matrix, TFT and Oled displays
 * Add support for Neo Coolcam Wifi Smart Power Plug
 * Add support for Michael Haustein ESP Switch
 * Add support for MQTT Client based on lwmqtt to be selected by #define MQTT_LIBRARY_TYPE MQTT_ARDUINOMQTT
 * Add support for Neo Coolcam Wifi Smart Power Plug
 * Add support for Michael Haustein ESP Switch
 * Add support for MQTT Client based on lwmqtt to be selected by #define MQTT_LIBRARY_TYPE MQTT_ARDUINOMQTT
 * Add support for DS3231 Real Time Clock
 * Add support for HX711 Load Cell with optional web GUI scale interface to demonstrate easy GUI plug-in
 * Add support for serial 8N2 communication to TasmotaModbus and TasmotaSerial libraries
 * Add support for RF transceiving using library RcSwitch (#2702)
 * Add support for Shelly 1 and Shelly 2 (#2789)
 * Add support for La Crosse TX20 Anemometer (#2654, #3146)
 * Add support for MP3 player using DFRobot RB-DFR-562 (#3723)
 * Add Support for Xiaomi-Philips Bulbs (#3787)
 * Add support for PCA9685 12bit 16pin hardware PWM driver (#3866)
 * Add support for EXS Relay V5.0 (#3810)
 * Add support for OBI Power Socket (#1988, #3944)
 * Add support for Teckin Power Socket with Energy Monitoring (#3950)
 * Add support for Pzem-003/017 DC Energy monitoring module (#3694)
 * Add support for Pzem-014/016 AC Energy monitoring module (#3694)
 * Add support for CSL Aplic WDP 303075 Power Socket with Energy Monitoring (#3991, #3996)
 * Add support for Tuya Dimmer (#469, #4075)
 * Add command Display to show all settings at once
 * Add command SerialSend5 to send raw serial data like "A5074100545293"
 * Add command WebRefresh 1000..10000 to control web page refresh in milliseconds. Default is 2345
 * Add command WeightRes 0..3 to control display of decimals for kilogram
 * Add command SetOption52 to control display of optional time offset from UTC in JSON messages (#3629, #3711)
 * Add command RGBWWTable to support color calibration (#3933)
 * Add command Reset 4 (reset to defaults but keep wifi params) and Reset 5 (as reset 4 and also erase flash) (#4061)
 * Add authentication to HTTP web pages
 * Add decimals as input to commands PowerSet, VoltageSet and CurrentSet
 * Add tools/decode-config.py by Norbert Richter to decode configuration data. See file for information
 * Add define USE_DISPLAYS for selecting image sonoff-display
 * Add auto reload of main web page to some web restarts
 * Add TasmotaModbus library as very basic modbus wrapper for TasmotaSerial
 * Add more API callbacks and document API.md
 * Add Wifi channel number to state message (#3664)
 * Add user configurable GPIO02 and GPIO03 on H801 devices (#3692)
 * Add network information to display start screen (#3704)
 * Add toggle function RGBW lights (#3695, #3697)
 * Add sleep to Nova Fitness SDS01X sensor (#2841, #3724, #3749)
 * Add Analog input AD0 enabled to sonoff-sensors.bin (#3756, #3757)
 * Add userid/password option to decode-status.py (#3796)
 * Add power value below 5W to Sonoff Pow R2 and S31 (#3745)
 * Add force_update to Home Assistant discovery (#3873)
 * Add delay after restart before processing rule sensor data (#3811)
 * Add rule triggers SWITCH1#BOOT and POWER1#BOOT (#3904, #3910)
 * Add Apparent Power and Reactive Power to Energy Monitoring devices (#251)
 * Add RF Receiver control to module MagicHome to be used on Arilux LC10 (#3792)
 * Add Hebrew language file (#3960)
 * Add whitespace removal from RfRaw and SerialSend5 (#4020)
