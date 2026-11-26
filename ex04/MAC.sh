#!/bin/sh
chmod +x MAC.sh
ifconfig | grep 'ether' | awk '{print $2}'