#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#ifdef DEBUG
	const char INTERFACE[] = "vcan0";
	const char LOGFILE[] = "vcanlogfile.log";
#else
	const char INTERFACE[] = "can0";
	const char LOGFILE[] = "canlogfile.log";
#endif

const int MAX_FRAMES = 512;
/* wait N sec before close the connection */
const int WAIT_UNTIL_CLOSE = 2; 

int can_socket;

struct data_can{
	 struct can_frame can_message; /* 16 byte */
	 uint32_t sec; /* 4 byte */
	 uint32_t usec; /* 4 byte */
};

/* open socket */
void open_port(){
	
    struct ifreq ifr;
    struct sockaddr_can addr;
    
    can_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if(can_socket < 0){
		exit(1);
    }
    
    strcpy(ifr.ifr_name, INTERFACE);
    if (ioctl(can_socket, SIOCGIFINDEX, &ifr) < 0){
        exit(1);
    }
    
    addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;
	
    fcntl(can_socket, F_SETFL, O_NONBLOCK);
    if (bind(can_socket, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        exit(1);
    }
}

void close_port(){
	close(can_socket);
}

void flush_data(const struct data_can frames_read[], const int nframes, 
				FILE * log_file){
	fwrite(frames_read, sizeof(struct data_can), nframes, log_file);
	return;
}

void read_frames(FILE * log_file){
    struct data_can frames_read[MAX_FRAMES];
    int nbytes = 0;
    int nframes = 0;
	struct timespec timer = {0, 0};
	int zero_time;

	clock_gettime(CLOCK_REALTIME, &timer);
    zero_time = timer.tv_sec;
    frames_read[nframes].sec = 0;
    
    while(1){
        struct timeval timeout = {0, 0};
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(can_socket, &readSet);
        clock_gettime(CLOCK_REALTIME, &timer);
        
        if (select((can_socket + 1), &readSet, NULL, NULL, &timeout) >= 0){
            if (FD_ISSET(can_socket, &readSet)){
                nbytes = read(can_socket, &frames_read[nframes].can_message, sizeof(struct can_frame));
                if(nbytes > 0 && nbytes >= sizeof(struct can_frame)){ 
					frames_read[nframes].sec = timer.tv_sec - zero_time;
					frames_read[nframes].usec = timer.tv_nsec / 1000;
					#ifdef DEBUG
						printf("%d.%d", frames_read[nframes].sec, frames_read[nframes].usec);
						printf(" id:%d len: %d\n", frames_read[nframes].can_message.can_id, frames_read[nframes].can_message.can_dlc);
					#endif
					++nframes;      
					/*flush data to file*/
					if (nframes == MAX_FRAMES){
						flush_data(frames_read, nframes, log_file);
						nframes = 0;
						/*Initialize in order to let the check works*/
						frames_read[nframes].sec = timer.tv_sec - zero_time;
					}
				}
			}
		}
		
		/*Check if there are frames to read, otherwise exit after WAIT_UNTIL_CLOSE seconds*/
		if (nframes > 0){
			if ((timer.tv_sec - zero_time) 
					- frames_read[nframes-1].sec > WAIT_UNTIL_CLOSE){
				flush_data(frames_read, nframes, log_file);
				break;
			}
		}else{
			if ((timer.tv_sec - zero_time) 
					- frames_read[nframes].sec > WAIT_UNTIL_CLOSE)
				break;
		}	
    }
    
    return;
}

int main(int argc, char * argv){
	
	FILE * log_file = fopen(LOGFILE, "wb");
	
    open_port();
    read_frames(log_file);
    close_port();
    
    return 0;
}
