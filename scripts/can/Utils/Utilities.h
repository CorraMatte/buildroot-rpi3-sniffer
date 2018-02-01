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
#endif

#define LOG_FILE "CAN"
#define NUMBER_CAN_FRAMES 1024
#define FILE_SIZE 500

#endif //CAN_UTILITIES_H

void initialize(const int BAUDRATE, const char* FOLDER);
int get_baudrate(const int BAUDRATE);
