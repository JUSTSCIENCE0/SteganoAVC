#pragma once

#include <windows.h>
#include <mutex>
#include <thread>
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
    StgnEngn();
    ~StgnEngn();

    STGNRES SetMetadata(const char* subsampling, int width, int height, float fps);
    STGNRES PutFrame(uint8_t* row_data, size_t size);

private:
    int     GetSampleSize(const char* subsampling);
    void    EncodeCycle();
    STGNRES EncodeProcess();

#ifdef WRITE_IN_FILE
    bool m_need_write = true;
    void WriteBufferInFile(const char* fname);
#endif // WRITE_IN_FILE

    std::mutex    m_mutex;
    std::thread   m_encode_thrd;
    InputMetadata m_in_metadata;
    InputFrames   m_in_frames;

    bool          m_is_stop = false;

};