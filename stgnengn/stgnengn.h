#pragma once

#include <windows.h>
#include <mutex>
#include <vector>
#include <list>

#include "stgnapi.h"

typedef struct _InputMetadata   InputMetadata;
typedef std::vector<uint8_t>    RowFrameData;
typedef std::list<RowFrameData> InputFrames;

struct _InputMetadata
{
    const char* m_color_format = "NONE";
    int         m_width = 0;
    int         m_height = 0;
    float       m_fps = 0;

    ~_InputMetadata()
    {
        delete[] m_color_format;
    }
};

class StgnEngn
{
public:
    StgnEngn(){};
    ~StgnEngn(){};

    STGNRES SetMetadata(const char* subsampling, int width, int height, float fps);
    STGNRES PutFrame(uint8_t* row_data, size_t size);

private:
    std::mutex    m_mutex;
    InputMetadata m_in_metadata;
    InputFrames   m_in_frames;

    int GetSampleSize(const char* subsampling);

#ifdef _DEBUG
    bool m_need_write = true;
    void WriteBufferInFile(const char* fname);
#endif // _DEBUG
};