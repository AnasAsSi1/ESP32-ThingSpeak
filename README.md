# ESP32 → ThingSpeak IoT Project

## Student Information
- *Name:* Anas Assi
- *University ID:* 12218153
- *University:* An-Najah National University
- *Course:* Internet of Things (IoT)

## Project Description
This project demonstrates how to use an ESP32 microcontroller with a DHT22 sensor to monitor temperature and humidity and send the readings to the ThingSpeak IoT cloud platform.

The project was developed and tested using the Wokwi online simulator. Temperature and humidity readings are transmitted to ThingSpeak every 20 seconds and displayed using live charts.

## Hardware Components
- ESP32 Development Board
- DHT22 Temperature and Humidity Sensor
- Connecting Wires
- Wokwi Simulator

## Wiring Connections

| DHT22 Pin | ESP32 Pin |
|---|---|
| VCC | 3V3 |
| SDA (DATA) | GPIO 15 |
| GND | GND |

The complete wiring configuration is available in diagram.json.

## Software and Libraries
- Arduino C++
- WiFi.h
- HTTPClient.h
- DHT.h
- Adafruit Unified Sensor
- Wokwi Simulator
- ThingSpeak IoT Platform

## How It Works
1. The ESP32 connects to the Wokwi-GUEST Wi-Fi network.
2. The DHT22 sensor measures temperature and humidity.
3. The ESP32 reads the sensor values.
4. The readings are sent to ThingSpeak using HTTP requests every 20 seconds.
5. ThingSpeak stores and displays the readings in two live charts.
6. The Serial Monitor displays the readings and confirms successful data transmission.

## ThingSpeak Configuration
- *Channel Name:* Anas_assi_12218153
- *Channel ID:* 3551485
- *Field 1:* Temperature (°C)
- *Field 2:* Humidity (%)
- *Channel Access:* Public
- *Update Interval:* 20 seconds

## Project Links

*ThingSpeak Public Channel:*

https://thingspeak.mathworks.com/channels/3551485

*Wokwi Simulation:*

https://wokwi.com/projects/478947266925603841

## How to Run
1. Open the Wokwi simulation link.
2. Open sketch.ino.
3. Replace YOUR_WRITE_API_KEY with your ThingSpeak Write API Key.
4. Start the simulation.
5. Open the Serial Monitor to check the readings and transmission status.
6. Open the ThingSpeak public channel to view the live temperature and humidity charts.

## Test Results

The project was successfully tested using the Wokwi simulator.

- *Initial Temperature:* 24°C
- *Initial Humidity:* 40%
- *Updated Temperature:* 29°C
- *Updated Humidity:* 55%
- *Data Transmission:* Successful
- *ThingSpeak Charts:* Successfully updated

The results confirm that the ESP32 can transmit sensor readings to the ThingSpeak cloud platform.

## Screenshots

Screenshots of the Wokwi circuit, Serial Monitor output, and ThingSpeak temperature and humidity charts are included in this repository.

## Conclusion

This project demonstrates a basic Internet of Things (IoT) application using ESP32, DHT22, Wi-Fi, and ThingSpeak. It successfully collects temperature and humidity readings, sends them to the cloud, and visualizes the data through publicly accessible graphs.
thingspeak.mathworks.com
