#!/usr/bin/python3.4
# Author: Matteo Corradini
#
# This Python script compresses and decompress the output files of the logger.
# The files are:
#   - gps.log: it contains the log about the GPS;
#   - extracted.1.csv: it contains the log about CAN frame;
#   - video.h264: it contains the video of the test.
# In case of decompression, the output files are stored in out/ folder.
# It uses pickle order to serialize the data structure, and gzip in order to
# create a smaller output file.

# IMPORT #######################################################################

import pickle
import sys
import gzip
import os

# VARIABLES ####################################################################

GPS_FILE = 'gps.log'
CAMERA_FILE = 'video.h264'
CAN_FILE = 'extracted.1.csv'
OUTPUT_FOLDER = 'out/'

c = dict()
opt = ['-c', '-x']
ARCHIVE_NAME = sys.argv[2]

# MAIN #########################################################################

# Get the file name and the action from the command line.
# Otherwise display the command help.
if len(sys.argv) < 3 or sys.argv[1] not in opt:
    print("Help:\n"
            "\t-c archive_name\t\tto create the archive (source file namen have"
            " to be: " + GPS_FILE + ", " + CAMERA_FILE + ", " + CAN_FILE + ")\n"
            "\t-x archive name\t\tto extract the archive\n")
    sys.exit(1)

# Compress the files
if sys.argv[1] == '-c':
    print("Creating the archive..")
    
    if not (ARCHIVE_NAME[len(ARCHIVE_NAME)-2:] == 'gz'):
        ARCHIVE_NAME += ".gz"
    c['gps'] = [l for l in open(GPS_FILE)]
    c['can'] = [l for l in open(CAN_FILE)]
    c['camera'] = open(CAMERA_FILE, 'rb').read()
    with gzip.open(ARCHIVE_NAME, 'wb') as f:
        f.write(pickle.dumps(c))
    print("Archive created in " + ARCHIVE_NAME)

# Decompress the file
else:
    if not os.path.exists(OUTPUT_FOLDER):
        os.makedirs(OUTPUT_FOLDER)
    print("Extracting the archvive..")

    with gzip.open(ARCHIVE_NAME, 'rb') as f:
        c = pickle.loads(f.read())

    f = open(OUTPUT_FOLDER + GPS_FILE, 'w')
    f.writelines(l for l in c['gps'])
    f.close()

    f = open(OUTPUT_FOLDER + CAN_FILE, 'w')
    f.writelines(l for l in c['can'])
    f.close()

    f = open(OUTPUT_FOLDER + CAMERA_FILE, 'wb')
    f.write(c['camera'])
    f.close()

    print("Archive successfully extracted in " + OUTPUT_FOLDER)




