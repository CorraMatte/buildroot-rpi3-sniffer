# buildroot-rpi3-sniffer

A Buildroot Linux system for Raspberry Pi 3, designed in order to be a CAN-BUS sniffer.

This project intends to create a complete Linux system, which includes: a root filesystem, a Linux kernel image and a bootloader in order to perform on a Raspberry Pi 3. It also includes the required packages in order to run the desired applications.
It intends to be lighter and smaller as possible, including only the necessary packages and driver to work as CAN-BUS sniffer.

To compile the project and check the requirements, please visit: https://buildroot.org/.

The relevant folder about the project are:

	- scripts/: It contains all the developed script in order to get data from the different sources. can/ contains the C/C++ scripts in order to retrieve data from the CANBUS, while gps/ contains the Python script in order to retrieve data from the GPSD daemon. utils/ contains Python scripts in order to automatize the building process. parser/ contains a Python script in order to compress and decompress the log files created by the platform.
	
	- output/target/etc/init.d: It contains all the bash scripts which run at the boot time of the platform in order to configure and log data.
	
	- output/target/root/scripts: It contains all the scripts created in order to log the data, inclused the raspicamera bash script.
	
	- board/raspberry/: It contains the files in ordet to automatize the process after the image and the built are done.
	
