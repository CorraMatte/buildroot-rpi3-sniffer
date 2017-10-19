# Author: Matteo Corradini
#
# This Python script log data from GPSD daemon through gps3 library.

# IMPORT #######################################################################

import time
import sys
from gps3 import gps3
from Utilities import FILE_NAME

# MAIN #########################################################################

gps_socket = gps3.GPSDSocket()  # Initialize socket with default setting
ds = gps3.DataStream()  # Initialize data stream
gps_socket.connect()  # Connect socket
gps_socket.watch()

# Initialize log file
FOLDER = '/test/'
f = open(FOLDER + FILE_NAME, 'w')
f.writelines('Time,Altitude,Latitude,Longitude,Speed,Climb\n')

# Initilize time settings
zero_time = time.time()
delta_time = zero_time
interval = float(sys.argv[1])

for new_ds in gps_socket:
    if new_ds:
        # Unpack the new data
        ds.unpack(new_ds)

        # Wait interval to save new data
        if (time.time() - delta_time) < interval:
            continue

        # Check if the new data contain reliable information
        if ds.TPV['alt'] != "n/a":
            data = [time.time() - zero_time, ds.TPV['alt'], ds.TPV['lat'],
                    ds.TPV['lon'], ds.TPV['speed'], ds.TPV['climb']]

            # Write and flush data into the file
            for d in data[:-1]:
                f.write(str(d) + ',')
            f.write(str(data[-1]) + '\n')
            f.flush()

            delta_time = time.time()
    else:
        # Sleep in order to save CPU and wait new data
        time.sleep(1)
