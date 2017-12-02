#ifndef CAN_UTILITIES_H
#define CAN_UTILITIES_H
#include "NanoLog.hpp"
#include "PCANBasic.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef DEBUG
#define FOLDER "/tmp/"
#else
#define FOLDER "/test/"
#endif

#define LOG_FILE "CAN"
#define NUMBER_CAN_FRAMES 1024//131072
#define FILE_SIZE 500

#endif //CAN_UTILITIES_H

void initialize(const int BAUDRATE);
int get_baudrate(const int BAUDRATE);
