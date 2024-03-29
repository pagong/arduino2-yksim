# src


## YkCore

The core cryptographic functions for the Yubikey simulator have been taken
from open source code written by [Yubico](http://www.yubico.com/).
The YkSim library is using code from the [libyubikey](https://github.com/Yubico/yubico-c) and
[yubikey-personalization](https://github.com/Yubico/yubikey-personalization) libraries.


## SoftTimer

This is a clever timer library for the Arduino which can be downloaded
from [arduino-softtimer](http://code.google.com/p/arduino-softtimer/).
I've only included those parts that are actually needed by the Yubikey simulator.

2019: `arduino-softtimer` has moved from google code to 
[github](https://github.com/prampec/arduino-softtimer).


## YkSim

These are the glue functions that make the Yubikey simulator work.
They're used by the example files which can be found in the `examples` directory.

They've been written and released with a GNU license by [pagong](mailto:pa90n9@gmail.com).

