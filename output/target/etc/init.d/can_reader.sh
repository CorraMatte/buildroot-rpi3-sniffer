#!/bin/sh

# device polling #
/etc/init.d/net_monitor

# device set up #
ip link set can0 type can bitrate 500000
ip link set can0 up

# start read #
/etc/init.d/candump_buildroot

# device poweroff #
ip link set can0 down

#poweroff
