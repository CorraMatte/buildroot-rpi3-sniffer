#!/bin/sh

sudo umount "$1"1
sudo umount "$1"2

sudo parted -s "$1" rm 1
sudo parted -s "$1" rm 2

sudo dd if=output/images/sdcard.img of="$1" bs=1M

