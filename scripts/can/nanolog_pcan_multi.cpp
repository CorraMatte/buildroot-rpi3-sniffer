#include <pthread.h>
#include <asm/types.h>
#include "Utils/Utilities.h"

/******** DATA STRUCTURES *****************************************************/

struct buffer_t{
    int index;
    TPCANMsg can_buffer[NUMBER_CAN_FRAMES];
};


/* GLOBAL VARIABLES ***********************************************************/

struct buffer_t buffer;


/* FUNCTIONS ******************************************************************/

void *consumer(void *){
    int con_index = 0;
    
    while (1){
        /** restart if the buffer is full */
        if (con_index > buffer.index){
            TPCANMsg frame_read = buffer.can_buffer[++con_index];
#ifdef VERBOSE
            printf("\n--C:id:%d len: %d--\n", frame_read.ID, frame_read.LEN);
#endif
            LOG_INFO << frame_read.ID <<','<< *((uint64_t*)frame_read.DATA);
            con_index = 0;
        }

        /** consume the buffer */
        while (con_index < buffer.index){
            TPCANMsg frame_read = buffer.can_buffer[con_index++];
#ifdef VERBOSE
            printf("--C:id:%d len: %d--\n", frame_read.ID, frame_read.LEN);
#endif
            LOG_INFO << frame_read.ID <<','<< *((uint64_t*)frame_read.DATA);
        }

        /** wait for new data */
        usleep(10);
    }
}

void read_frames(const int WAIT_TIME){
    buffer.index = 0;
    pthread_t pt_consumer;
    pthread_create(&pt_consumer, NULL, consumer, NULL);

    /** Timer settings */
    struct timespec timer = {0, 0};
    clock_gettime(CLOCK_REALTIME, &timer);
    int zero_time_sec = timer.tv_sec;
    int last_time_recv = timer.tv_sec;

    while(1){
        clock_gettime(CLOCK_REALTIME, &timer);

        if (CAN_Read(PCAN_USBBUS1,&buffer.can_buffer[buffer.index],NULL) 
			!= PCAN_ERROR_QRCVEMPTY) {
#ifdef VERBOSE
            printf("\n--P: id:%d len: %d", buffer.can_buffer[buffer.index].ID,
                buffer.can_buffer[buffer.index].LEN);
#endif
            ++buffer.index;
            if (buffer.index == NUMBER_CAN_FRAMES)
                buffer.index = 0;

            last_time_recv = timer.tv_sec;
        }

#ifdef TEST_LENGTH
        /** Terminate the test after TEST_LENGTH minutes */
        if (timer.tv_sec - zero_time_sec > 60 * TEST_LENGTH)
            break;
#endif

        /** Check if there are frames to read, otherwise exit after 
         *  WAIT_UNTIL_CLOSE seconds*/
        if ((timer.tv_sec - last_time_recv) > WAIT_TIME)
            exit(2);

		usleep(10);
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

