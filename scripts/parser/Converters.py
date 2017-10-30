#!/usr/bin/python3.4

# IMPORT #######################################################################

import pandas as pd
import ffmpy
import os

# FUNCTIONS ####################################################################

# Get CAN frame information from the file line
def line2array(line, zero_time=.0):
    # Time calculation
    line = line.split()
    time = line[1].replace(']', '')
    time = time.split(':')
    hour = float(time[0])
    minutes = float(time[1])
    time = (float(time[2]) + hour * 60 * 60 + minutes * 60) - zero_time
    time = format(time, '.6f')

    # Can data
    can_id = hex(int(line[2].split(',')[0]))[2:].upper()
    num = int(line[2].split(',')[1])
    payload = "{0:b}".format(num)

    if len(payload) < 64:
        payload = '0' * (64 - len(payload)) + payload
    payload = payload[::-1]
    for i in range(8):
        payload = payload[0:i * 8] + payload[i * 8:(i + 1) * 8][::-1] + \
                  payload[(i + 1) * 8:]

    return [time, '1', can_id, 'Rx', payload, '0', '0']


# Convert canframe file to a stardard format
def convert_canframe_file(can_file, output_canfile):
    rows = []

    log_file = open(can_file)
    rows.append(line2array(log_file.readline()))
    zero_time = float(rows[0][0])
    rows[0][0] = format(0, '.6f')

    for line in log_file:
        rows.append(line2array(line, zero_time))

    df = pd.DataFrame(rows, columns= \
        "timestamp,channel,can_id,type,payload,length,bitcount".split(","))

    # Export to csv
    df.to_csv(output_canfile, index=False)


# Convert Video to MP4
def convert_video_to_mp4(camera_file, output_camera_file):
    ff = ffmpy.FFmpeg(
        inputs={camera_file: None},
        outputs={output_camera_file: None}
    )

    ff.run()
