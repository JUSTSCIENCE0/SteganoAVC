#pragma once

#include <stdint.h>

#ifdef _DEBUG
//#define WRITE_IN_FILE
#define LOG_TO_STDOUT
#endif //_DEBUG

#define STGN_MAX_BUFFER_IN 1073741824 //input buffer no more than 1 GB

typedef int32_t STGNRES;

//macros
#define STGN_BREAK_FAILED(arg) if (arg < 0) return arg
#define STGN_IS_SUCCESSED(arg) arg == 0
#define STGN_IS_FAILED(arg)    arg < 0
#define STGN_ISNT_FAILED(arg)  arg >= 0

//no errors
#define STGN_OK     0x0

//warnings
#define STGN_IN_EMPTY    0x1

//errors
#define STGN_INVALID_ARG 0x80000001
#define STGN_WRONG_SIZE  0x80000002
#define STGN_WRONG_DATA  0x80000003
#define STGN_FAIL        (~0)

//functions
void PrintInfoInStd(STGNRES code);
