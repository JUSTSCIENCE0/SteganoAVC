#pragma once

#define STGN_MAX_BUFFER_IN 64

typedef int32_t STGNRES;

#define STGN_BREAK_FAILED(arg) if (arg < 0) return arg
#define STGN_IS_SUCCESSED(arg) arg == 0
#define STGN_ISNT_FAILED(arg)  arg >= 0

#define STGN_OK     0x0

#define STGN_INVALID_ARG 0x80000001
#define STGN_WRONG_SIZE  0x80000002
#define STGN_WRONG_DATA  0x80000003
#define STGN_FAIL   (~0)
