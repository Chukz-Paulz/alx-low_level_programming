#!/bin/bash
wget -p .. https://raw.githubusercontent.com/Chukz-Paulz/alx-low_level_programming/master/0x18-dynamic_libraries/libjack_hack.so
export LD_PRELOAD="$PWD/../libjack_hack.so"
