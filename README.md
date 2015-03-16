RPiTextIP
===============
Sends the IP address of your Raspberry Pi through text message. This makes connecting to the Pi through ssh simpler and allows people to find the IP address without a serial connection and login.

Setup
=========
In terminal: from path home/pi/
```
sudo nano /etc/inittab
```

Scroll down to 
```
1:2345:respawn:/sbin/getty 115200 tty1
```

and change to
```
#1:2345:respawn:/sbin/getty 115200 tty1
```

under that line type
```
1:2345:respawn:/bin/login -f pi tty1 </dev/tty1 >/dev/tty1 2>&1
```

Control-o to save and Control-x to exit nano

In terminal, type in
```
sudo nano .bashrc
```

Scroll down to end of file and type 
```
/home/pi/RPiTextIP/./execute_bash.sh
```
