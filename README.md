# RFIDSecureKey

DOOR_LOCK: Arduino-based door look system with RFID id password

In this Arduino project, an LCD display is utilized along with a green LED to indicate when the door is open, and a red LED to signal when the door is closed. To facilitate the opening and closing of the door, a servo motor is incorporated. The user is prompted to input a password through the serial monitor.

The project then proceeds to compare the entered password with a predefined constant RFID password. If the entered password matches the RFID password, the door is opened, and the green LED is illuminated. Conversely, if there is no match, the door remains closed, and the red LED is turned on.
