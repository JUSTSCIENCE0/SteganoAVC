#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "stgnapi.h"

void PrintInfoInStd(STGNRES code)
{
    switch (code)
    {
    case STGN_OK:
        //printf("STGNENGN: All ok\n");
        break;
    case STGN_IN_EMPTY:
        printf("Warning: Incoming buffer is empty\n");
        break;
    case STGN_INVALID_ARG:
        printf("Error: Function was called with invalid parameters\n");
        break;
    case STGN_WRONG_SIZE:
        printf("Error: Received frame size does not match data format\n");
        break;
    case STGN_WRONG_DATA:
        printf("Error: wrong data format\n");
        break;
    case STGN_FAIL:
        printf("Error: runtime fail\n");
        break;
    default:
        printf("Function completed with unknown code\n");
        break;
    }
}