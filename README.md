# usb-password-tools
I am currently developing a password manager that leverages microcontroller technology to streamline the login process. The device, designed to mimic a keyboard, will feature a compact OLED screen to allow users to easily scroll through their password list. I aim to expedite the process of password entry and multifactor authentication, while maintaining optimal security.

This project was borne out of my personal dissatisfaction with having to key in lengthy, intricate passwords and the constant need to input a sudo password multiple times per day. My vision is a minimalist device, devoid of an OS that could be targeted by hackers, capable of both storing and generating passwords. The device could also potentially accommodate U2F/FIDO2/TOTP protocols to function as a security key.

I'm contemplating the use of a capacitive touchpad over mechanical buttons to achieve quiet and dependable input. The touchpad would include dedicated buttons for frequently used passwords and a scroll pad for list navigation.

This project is in its nascent stage and I welcome any suggestions. The device should be able to function as a USB keyboard without the need for pairing with other devices. While I wish to keep the design as straightforward as possible, I am not averse to acquiring new skills if they facilitate the addition of useful features. Ultimately, my objective is to save time spent on password management, without compromising the security of user accounts.

This endeavour also provides me with an opportunity to delve into KiCAD and PCB fabrication. I find the Raspberry Pi Pico RP2040 particularly intriguing due to its appealing features and cost-effectiveness. Additionally, I have a few STM32 boards on hand for experimentation purposes.
