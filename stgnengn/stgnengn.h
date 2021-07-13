#pragma once

#include <windows.h>

typedef struct {
    char*   m_color_format;
    int     m_width;
    int     m_height;
    float   m_fps;
} InputMetadata;

class StgnEngn
{
public:
    InputMetadata m_in_metadata;
};

extern "C" 
{

}