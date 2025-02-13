# lora-emitter-project

This project implements a LoRa emitter board that regularly transmits air quality data using the Grove Air Quality Sensor. The data includes the air quality index (Q) and the sensor voltage (Vsensor). 

## Project Structure

```
lora-emitter-project
├── src
│   ├── main.cpp
│   └── Grove_Air_Quality_Sensor_Library
│       ├── Air_Quality.cpp
│       └── Air_Quality.h
├── include
│   └── config.h
├── Makefile
└── README.md
```

## Files Description

- **src/main.cpp**: The main program for the emitter board. It initializes the Air Quality sensor with the specified pins (A2 for Vsensor and A1 for Vheater), sets up LoRa transmission, and regularly sends the air quality index (Q) and sensor voltage (Vsensor) via LoRa.

- **src/Grove_Air_Quality_Sensor_Library/Air_Quality.cpp**: Contains the implementation of the Air_Quality class. It includes methods for initializing the sensor, calculating the slope for readings, and averaging the voltage from the sensor.

- **src/Grove_Air_Quality_Sensor_Library/Air_Quality.h**: Header file that declares the Air_Quality class and its methods. It includes necessary libraries and defines the structure of the class.

- **include/config.h**: Contains configuration constants and settings for the project, such as BUFFER_SIZE and parameters for LoRa transmission and sensor configuration.

- **Makefile**: Used to compile the project. It includes rules for building the source files and linking them into an executable, along with necessary compiler flags.

## Setup Instructions

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Ensure that all dependencies are installed, including the Grove Air Quality Sensor library.
4. Modify the `config.h` file to set the appropriate configuration constants.
5. Use the Makefile to compile the project:
   ```
   make
   ```
6. Upload the compiled program to the emitter board.

## Usage

Once the program is uploaded, the emitter board will start sending the air quality index and sensor voltage via LoRa at regular intervals. Monitor the receiving end to capture and process the transmitted data.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.