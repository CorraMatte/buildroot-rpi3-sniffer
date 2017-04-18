#!/usr/bin/python3.4
import sys
import subprocess

# CONSTANTs #
OFFSET_BYTES=2
BLANK_LINES=2
KB=0.0001
GB=1000
FREE_SPACE_PERC=10/100
PARTITION_TO_RESIZE=2

# INITIALIZATION VARIABLES #
disk = sys.argv[1]
disk_size = 0

# GET DISK SIZE #
stdout = subprocess.check_output(['sudo', 'parted', '-s', disk, 'print'], universal_newlines=True)
stdout = stdout.split("\n")
for line in stdout:
	if line.count(disk) > 0:
		line = line.split()
		disk_size = line[len(line)-1]
		byte = disk_size[len(disk_size)-OFFSET_BYTES:]	
		disk_size = float(disk_size[:len(disk_size)-OFFSET_BYTES].replace(',','.'))
		if byte == "GB":
			disk_size = disk_size * GB
		elif byte == "KB":
			disk_size = disk_size * KB

# GET FIRST PARTITION SIZE #
first_par_size = stdout[len(stdout)-BLANK_LINES-2].split()[3]
first_par_size = float(first_par_size[:len(first_par_size)-OFFSET_BYTES]
					.replace(',','.'))

# RESIZE PARTITION #
free_space = disk_size - first_par_size
root_par_size = free_space - free_space * FREE_SPACE_PERC
subprocess.call(['sudo', 'parted', '-s', disk, 'resizepart', str(PARTITION_TO_RESIZE), str(root_par_size)])
subprocess.call(['sudo', 'resize2fs', disk + str(PARTITION_TO_RESIZE)])
