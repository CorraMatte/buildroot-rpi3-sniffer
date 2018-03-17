#!/bin/sh

set -u
set -e

DRIVER_VERSION=8.4.0
KERNEL_VERSION=4.9.43-v7
PCAN_DIR="${TARGET_DIR}"/lib/modules/"${KERNEL_VERSION}"/kernel/drivers/peak/

cd "${BUILD_DIR}"/peak-driver-"${DRIVER_VERSION}"
make clean
make -C driver PCIEC=NO PCI=NO ISA=NO PCC=NO DNG=NO KERNEL_LOCATION="${BUILD_DIR}"/linux-84a1781639429747b894f5121476b514a6a20651/ ARCH=arm CROSS_COMPILE="${HOST_DIR}"/usr/bin/arm-buildroot-linux-uclibcgnueabihf-

if [ ! -d "$PCAN_DIR" ]; then
	echo "here" 
	mkdir "$PCAN_DIR"
fi

cp "${BUILD_DIR}"/peak-driver-"${DRIVER_VERSION}"/driver/pcan.ko "$PCAN_DIR"
