#ifndef CAN_UTILITIES_H
#define CAN_UTILITIES_H
#include "NanoLog.hpp"
#include "PCANBasic.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define LOG_FILE "CAN"
#define NUMBER_CAN_FRAMES 1024
#define FILE_SIZE 500

#endif

void initialize(const int BAUDRATE, const char* TEST_FOLDER);
int get_baudrate(const int BAUDRATE);
