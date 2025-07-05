# Smart-Environmental-Monitoring-and-Control-System
_🔧 Project Description_
This **Arduino** project monitors temperature and humidity using the DHT11 sensor and provides a visual and audio alert system based on environmental conditions. It uses LEDs, a buzzer, and a fan to indicate different temperature/humidity levels.

_📋 Features_
Uses the DHT11 sensor to measure temperature and humidity.
Controls:
Orange LED – indicates critical high temperature/humidity.
Yellow LED – indicates moderate conditions.
Green LED – indicates safe/normal conditions.
Buzzer – sounds alarm when critical levels are reached.
Fan – turns on to reduce temperature in critical conditions.
Displays temperature and humidity data on the Serial Monitor.

_📌 Pin Configuration_
Component	Arduino Pin	Description
DHT11 Sensor	D2	Temperature and humidity input
Green LED	D13	Safe condition indicator
Yellow LED	D12	Moderate condition indicator
Orange LED	D11	Critical condition indicator
Buzzer	D10	Audible alert
Fan	D9	Cooling system (simulated)

_🔄 Logic Flow_
Initialization:
All devices (LEDs, fan, buzzer) and the DHT11 sensor are initialized.
Serial communication is set up to display temperature and humidity readings.

Reading Sensor Values:
Every 2 seconds, the DHT11 reads the current temperature and humidity.
If sensor reading fails, a message is displayed and the cycle is skipped.

Condition Checks & Actions:
Critical Condition:
Temperature ≥ 40°C or Humidity ≥ 60%
Orange LED, Fan, and Buzzer are turned ON.
Moderate Condition:
20°C ≤ Temperature < 40°C or 40% ≤ Humidity < 60%
Yellow LED ON; Fan and Buzzer OFF.
Safe Condition:
Temperature < 20°C and Humidity < 40%
Green LED ON; all others OFF.

Serial Output:
Temperature and humidity are printed to the Serial Monitor for debugging and monitoring.

_📷 Expected Behavior_
Green LED: Normal/safe environment
Yellow LED: Mild environmental change
Orange LED + Fan + Buzzer: Dangerous/high levels (requires action)

_🧾 Dependencies_
DHT.h – You must install the DHT sensor library. You can get it via:
Arduino IDE → Library Manager → Search for “DHT sensor library” by Adafruit

_🔄 Delay_
The system waits 2 seconds between sensor reads using delay(2000); to allow the DHT11 to refresh its data.


