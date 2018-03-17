#include "Utilities.h"

/* Get the correct PCAN baudrate  value */
int get_baudrate(const int BAUDRATE){
    switch (BAUDRATE){
        case 5:// 5 kBit/s
            return PCAN_BAUD_5K;
        case 10:// 10 kBit/s
            return PCAN_BAUD_10K;
        case 20:// 20 kBit/s
            return PCAN_BAUD_20K;
        case 33:// 33,33 kBit/s
            return PCAN_BAUD_33K;
        case 47:// 47 kBit/s
            return PCAN_BAUD_47K;
        case 50:// 50 kBit/s
            return PCAN_BAUD_50K;
        case 83:// 83.333 kBit/s
            return PCAN_BAUD_83K;
        case 95://  95,238 kBit/s
            return PCAN_BAUD_95K;
        case 100:// 100 kBit/s
            return PCAN_BAUD_100K;
        case 125:// 125 kBit/s
            return PCAN_BAUD_125K;
        case 250:// 250 kBit/s
            return PCAN_BAUD_250K;
        case 500:// 500 kBit/s
            return PCAN_BAUD_500K;
        case 800:// 800 kBit/s
            return PCAN_BAUD_800K;
        case 1000://   1 MBit/s
            return PCAN_BAUD_1M;
    }
}

/* Initilize PCAN and Nanolog */
void initialize(const int BAUDRATE, const char* TEST_FOLDER){
#ifdef DEBUG
	TEST_FOLDER = "/tmp/";
#endif
    TPCANStatus Status;
	printf("Dir: %s, File: %s\n\n", TEST_FOLDER, LOG_FILE);
    nanolog::initialize(nanolog::GuaranteedLogger(), TEST_FOLDER, LOG_FILE, FILE_SIZE);
    if (Status = CAN_Initialize(PCAN_USBBUS1, get_baudrate(BAUDRATE), 0, 0, 0)
        != PCAN_ERROR_OK){
#ifdef VERBOSE            
			printf("CAN not found 0x%x\n", Status);
#endif
        exit(Status);
	}
    return;
}
