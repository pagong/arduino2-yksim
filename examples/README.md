# examples


## yksEEinit0

Change the AES-128 key, the public and private ids and the static password to your personal likings (and keep them private).
Upload the code to your Arduino Board to initialize the EEPROM. This needs to be done once, whenever you change the keys.


## yksButton1

Solder a button switch to pin 3 and GND of your 'ProMicro' board and upload this code into your Board.
This will turn your Board into an USB keyboard that emits keyboard scan codes whenever you press the button.
Every time you press the button for a short time, a unique new Yubikey compatible OTP will be 'typed' by the Board.
If you press the button for a longer time, the static, secret password will by 'typed' by the 'ProMicro'.


