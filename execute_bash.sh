#! /bin/bash

chmod a+x execute_bash.sh	//Makes script executable
chmod 777 execute_bash.sh	//Gives script root rights

sudo /home/pi/RPiTextIP/./getIP
sudo python /home/pi/RPITextIP/script.py
sudo rm address.txt 
