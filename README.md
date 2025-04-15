# 🤖 Autonomous Obstacle Avoiding Bot

An intelligent Arduino-based robot that can navigate autonomously by detecting and avoiding obstacles in its path using ultrasonic sensing and real-time decision making. This project was developed as part of the **Design Lab course** at **The LNM Institute of Information Technology (LNMIIT), Jaipur**.

---

## 📌 Project Overview

This robot uses an ultrasonic sensor mounted on a servo motor to scan its environment. The Arduino Uno processes distance data and makes decisions to move forward, turn, or stop based on nearby obstacles. A liquid crystal display (LCD) is used to show the movement direction and status.

---

## 🧠 Features

- Autonomous obstacle detection and avoidance
- Directional decision-making using servo-based scanning
- Real-time feedback via 16x2 I2C LCD
- Smooth movement with dual DC motors via motor driver (L293D)
- Clear separation of movement logic (forward, reverse, left, right, stop)

---

## 🛠️ Hardware Used

- Arduino UNO
- Ultrasonic Sensor (HC-SR04)
- Servo Motor (SG90)
- L293D Motor Driver IC
- 2 BO DC Motors (200 RPM)
- 16x2 I2C LCD Display
- Chassis, Wheels, Jumper Wires, 9V Battery

---

## 💻 Software & Libraries

- Arduino IDE
- `Servo.h`
- `NewPing.h`
- `LiquidCrystal_I2C.h`
- `Wire.h`

---

## 🔧 How It Works

1. The ultrasonic sensor mounted on a servo rotates to check distance in front, left, and right.
2. If no obstacle is detected, the bot moves forward.
3. If an obstacle is detected within 25 cm:
   - It stops and scans both sides.
   - Turns toward the direction with more free space.
   - Resumes movement.
4. LCD displays current status ("Forward", "Stop", "Going Left", etc.)

---

## 🚀 Setup Instructions

1. Connect the components as per the wiring in the `block diagram`.
2. Upload the Arduino code from [`Obstacle Avoiding Bot.txt`](./Obstacle%20Avoiding%20Bot.txt) using Arduino IDE.
3. Power the Arduino with a 9V battery or USB.
4. Watch your bot navigate around obstacles autonomously!

---

## 📊 Experimental Results

The bot successfully:
- Detected obstacles using the ultrasonic sensor.
- Calculated distance and navigated toward obstacle-free paths.
- Executed left and right turns based on real-time scanning logic.

---

## 📚 References

- [Arduino Official Documentation](https://www.arduino.cc/)
- [HC-SR04 Datasheet](https://components101.com/sensors/hc-sr04-ultrasonic-sensor)
- [L293D Motor Driver IC](https://www.ti.com/product/L293D)
- [NewPing Library](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home)

---

## 👤 Authors

- **Hardik Agrawal** - [22uec045]
- **Harsh Agrawal** - [22uec046]  
*Supervisor: Dr. Bharat Verma*

---

## 📄 License

This project is open for educational and research use. Please give proper credit to the authors if reused or modified.

---



