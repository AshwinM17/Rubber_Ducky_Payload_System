# Rubber_Ducky_Payload_System

## Abstract:
This project demonstrates a keystroke injection attack simulation using a USB-based
Rubber Ducky payload system. The system uses an Arduino Pro Micro to emulate a keyboard
that injects platform-specific malicious commands into a target machine, depending on the
mode addressed by number of external button presses. It simulates real-world attack
scenarios, such as copying sensitive files, encrypting them with a secret passphrase, and
leaving a ransom note. The purpose of this project is to illustrate the dangers of USB-based
attacks and raise awareness about securing endpoints against such threats. This payload
system can be used for penetration testing and cybersecurity education to help reinforce good
security practices.


## Introduction:
USB-based keystroke injection allows attackers to compromise systems by simply
plugging in a device that acts as a keyboard. Such attacks have been popularised through
devices like the USB Rubber Ducky, which can execute pre-programmed scripts by
simulating fast, automated keystrokes.


This project uses Arduino Pro Micro. When connected to a target system, the
microcontroller emulates a keyboard and delivers platform-specific malicious commands
based on the operating system of the target device. A single button press triggers the Linux
payload, while a double button press triggers the Windows payload. Both payloads copy all
.docx and .pdf files from a specified folder, encrypt them, and leave a ransom note
demanding payment for the decryption key.


This project aims to demonstrate the ease with which such attacks can be executed
and to stress the importance of proper endpoint protection measures, such as disabling USB
ports or employing robust access control mechanisms.
