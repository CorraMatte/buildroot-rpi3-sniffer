#!/usr/bin/python3
# coding=utf-8
"""creates Google Earth kml file (/tmp/gps3_live.kml) for realtime (4 second GE default) updates of gps coordinates and history
# Concept from Jaroslaw Zachwieja <grok!warwick.ac.uk> &  TJ <linux!tjworld.net>
# from their work in gegpsd.py included in gpsd project (http://catb.org/gpsd)
"""
import time

from gps3 import gps3  # Moe, remember to CHANGE to straight 'import gps3' if not installed,

# or check which Python version it's installed in. You forget sometimes.

__author__ = 'Moe'
__copyright__ = 'Copyright 2014-2016 Moe'
__license__ = 'MIT'
__version__ = '0.33.2'

link_file = '/tmp/gps3_live.kml'  # AFAIK, 'Links' call href on time events or entry/exit  Multiple href may be possible.
gps3data_file = '/tmp/gps3_static.kml'
gps3data_history = []

link_data = ('<?xml version=\'1.0\' encoding=\'UTF-8\'?>\n'
             '<kml xmlns=\'http://www.opengis.net/kml/2.2\' xmlns:gx=\'http://www.google.com/kml/ext/2.2\' xmlns:kml=\'http://www.opengis.net/kml/2.2\' xmlns:atom=\'http://www.w3.org/2005/Atom\'>\n'
             '<NetworkLink>\n'
             '    <name>GPS3 Live</name>\n'
             '    <Link>\n'
             '        <href>{0}</href>\n'
             '        <refreshMode>onInterval</refreshMode>\n'
             '    </Link>\n'
             '</NetworkLink>\n'
             '</kml>').format(gps3data_file)  # inserts 'the file' into a refresh mode default 4 second
f = open(link_file, 'w')
f.write(link_data)
f.close()

gpsd_socket = gps3.GPSDSocket()
gpsd_socket.connect(host='127.0.0.1', port=2947)
gpsd_socket.watch()
data_stream = gps3.DataStream()

try:
    for new_data in gpsd_socket:
        if new_data:
            data_stream.unpack(new_data)
        if data_stream.TPV['lat'] != 'n/a':
            speed = data_stream.TPV['speed']
            latitude = data_stream.TPV['lat']
            longitude = data_stream.TPV['lon']
            altitude = data_stream.TPV['alt']

            if data_stream.TPV['track'] == 'n/a': heading = data_stream.TPV['track']  # 'track' frequently is missing and returns as 'n/a'
            else: heading = round(data_stream.TPV['track'])  # and heading precision in hundreths is just clutter.

            gps3data_history.append(longitude)
            gps3data_history.append(latitude)
            gps3data_history.append(altitude)
            hist_string = str(gps3data_history).replace(' ', '')  # GE > 7.1.xxxx spits up on spaces in <coordinates>

            static_file = ('<?xml version = \'1.0\' encoding = \'UTF-8\'?>\n'
                           '<kml xmlns = \'http://www.opengis.net/kml/2.2\' xmlns:gx = \'http://www.google.com/kml/ext/2.2\' xmlns:kml = \'http://www.opengis.net/kml/2.2\' xmlns:atom = \'http://www.w3.org/2005/Atom\'>\n'
                           '<Folder>\n'
                           '    <description> Frankie likes walking and stopping </description>\n'

                           '    <Placemark id = \'point\'>\n'
                           '        <name>{0:.2f} m/s {4}°</name>\n'
                           '        <description>Current gps location\nAltitude: {3} Metres</description>\n'
                           '        <LookAt>\n'
                           '            <longitude>{1}</longitude>\n'
                           '            <latitude>{2}</latitude>\n'
                           '            <range>600</range>\n'
                           '            <tilt>0</tilt>\n'
                           '            <heading>0</heading>\n'
                           '        </LookAt>\n'
                           '        <Point>\n'
                           '            <coordinates>{1},{2},{3}</coordinates>\n'
                           '        </Point>\n'
                           '    </Placemark>\n'

                           '    <Placemark id = \'path\'>\n'
                           '        <name>Pin Scratches</name>\n'
                           '        <description>GPS Trail of Tears</description>\n'
                           '        <LineString>\n'
                           '        <color>7f0000ff</color>\n'
                           '        <width>20</width>\n'
                           '            <tessellate>1</tessellate>\n'
                           '            <coordinates>{5}</coordinates>\n'
                           '        </LineString>\n'
                           '    </Placemark>\n'
                           '</Folder>\n'
                           '</kml>').format(speed, longitude, latitude, altitude, heading, hist_string.strip('[]'))

            f = open(gps3data_file, 'w')
            f.write(static_file)
            f.close()

        else:
            time.sleep(.1)
        time.sleep(.8)  # default GE refresh rate is 4 seconds, therefore no refresh older than ~1 second from itself.
except KeyboardInterrupt:
    gpsd_socket.close()
    print('\nTerminated by user\nGood Bye.\n')
# End
