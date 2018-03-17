################################################################################
#
# PCAN DRIVER
#
################################################################################
PCAN_VERSION = 8.4.0
PCAN_SOURCE = foo-$(FOO_VERSION).tar.xz
PCAN_SITE = http://www.peak-system.com/fileadmin/media/linux/files/
PCAN_LICENSE = GPLv2
PCAN_LICENSE_FILES = COPYING
PCAN_MODULE_MAKE_OPTS = "-C driver NET=NETDEV_SUPPORT PCIEC=NO PCI=NO ISA=NO PCC=NO DNG=NO"


$(eval $(kernel-module))
$(eval $(generic-package))
