#include "Utils/Utilities.h"

/* FUNCTIONS ******************************************************************/

void read_frames(const int WAIT_TIME){
    TPCANMsg frame_read;

    struct timespec timer = {0, 0};
    clock_gettime(CLOCK_REALTIME, &timer);
    int zero_time_sec = timer.tv_sec;
    int last_time_recv = timer.tv_sec;

    while(1) {
        clock_gettime(CLOCK_REALTIME, &timer);

        if (CAN_Read(PCAN_USBBUS1, &frame_read, NULL) 
			!= PCAN_ERROR_QRCVEMPTY) {
#ifdef VERBOSE
            printf(" id:%d len: %d\n", frame_read.ID, frame_read.LEN);
#endif
            LOG_INFO << frame_read.ID <<','<< *((uint64_t*)frame_read.DATA);
            last_time_recv = timer.tv_sec;
        }

#ifdef TEST_LENGTH
        /** Terminate the test after TEST_LENGTH minutes */
        if (timer.tv_sec - zero_time_sec > 60 * TEST_LENGTH)
            break;
#endif

        /** Check if there are frames to read, otherwise exit after 
         *  WAIT_UNTIL_CLOSE seconds */
        if ((timer.tv_sec - last_time_recv) > WAIT_TIME)
            exit(1);
    }
    return;
}


/* MAIN ***********************************************************************/

int main(int argc, char * argv[]){
	int WAIT_TIME = atoi(getenv("WAIT_TIME"));
	int BAUDRATE = atoi(getenv("BAUDRATE"));

    initialize(BAUDRATE);
    read_frames(WAIT_TIME);
    return 0;
}
