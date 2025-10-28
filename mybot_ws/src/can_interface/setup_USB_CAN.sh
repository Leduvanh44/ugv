#setup_USB_CAN.sh
#!/bin/bash
str=".................Setting up USB_CAN ............."
echo $str
sudo slcand -o -c -f -s8 /dev/ttyUSB0 can0
sudo ifconfig can0 up
echo "................USB_CAN Connected..............."
echo $str
