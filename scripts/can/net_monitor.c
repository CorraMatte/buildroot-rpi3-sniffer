#include <libudev.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

int main (void)
{
	struct udev *udev;
	struct udev_device *dev;

   	struct udev_monitor *mon;
	int fd;
	
	/* Create the udev object */
	udev = udev_new();
	if (!udev) {
		printf("\nCan't create udev\n");
		exit(1);
	}
	
	/* Set up a monitor to monitor net devices */
	mon = udev_monitor_new_from_netlink(udev, "udev");
	if (mon == NULL) {
		printf("\nCan't create mon\n"); 
		exit(1);
	}
	
	udev_monitor_filter_add_match_subsystem_devtype(mon, "net", NULL);
	udev_monitor_enable_receiving(mon);
	
	/* Get the file descriptor (fd) for the monitor.
	   This fd will get passed to select() */
	fd = udev_monitor_get_fd(mon);
	if (fd < 0) {
		printf("\nCan't create fd\n"); 
		exit(1);
	}
	/* Begin polling for udev events. */
	while (1) {
		/* Set up the call to select(). */  
		fd_set fds;
		struct timeval tv;
		int ret;
		
		FD_ZERO(&fds);
		FD_SET(fd, &fds);
		tv.tv_sec = 0;
		tv.tv_usec = 0;
		
		ret = select(fd+1, &fds, NULL, NULL, &tv);
		
		/* Check if our file descriptor has received data. */
		if (ret > 0 && FD_ISSET(fd, &fds)) {
			dev = udev_monitor_receive_device(mon);
			if (dev) {
			    udev_device_unref(dev);
			    return 0; 
			}else {
				printf("\nNo Device from receive_device(). An error occured.\n");
			}
		}
		usleep(250);
	}

	udev_unref(udev);

	return 0;       
}

