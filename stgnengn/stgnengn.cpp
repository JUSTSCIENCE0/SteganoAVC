#define _CRT_SECURE_NO_WARNINGS

#include "stgnengn.h"

STGNRES StgnEngn::SetMetadata(const char* subsampling, int width, int height, float fps)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    m_in_metadata.m_color_format = subsampling;
    m_in_metadata.m_width        = width;
    m_in_metadata.m_height       = height;
    m_in_metadata.m_fps          = fps;

    return STGN_OK;
}

STGNRES StgnEngn::PutFrame(uint8_t* row_data, size_t size)
{
    if (!row_data || !size)
        return STGN_INVALID_ARG;

    std::lock_guard<std::mutex> lock(m_mutex);

    int sample_size = GetSampleSize(m_in_metadata.m_color_format);
    STGN_BREAK_FAILED(sample_size);

    size_t check_size = (size_t)sample_size * m_in_metadata.m_width * m_in_metadata.m_height;
    if (size != check_size)
        return STGN_WRONG_SIZE;

    RowFrameData frame(row_data, row_data + size);
    m_in_frames.push_back(frame);

    if (m_in_frames.size() > STGN_MAX_BUFFER_IN)
    {
        m_in_frames.pop_front();

#ifdef _DEBUG
        WriteBufferInFile("Z:\\test.yuv");
#endif // _DEBUG
    }

    return STGN_OK;
}

int StgnEngn::GetSampleSize(const char* subsampling)
{
    if (!subsampling)
        return STGN_INVALID_ARG;

    if (!strcmp(subsampling, "Y42B"))
        return 2;

    return STGN_FAIL;
}

#ifdef _DEBUG
void StgnEngn::WriteBufferInFile(const char* fname)
{
    if (!m_need_write) return;
    m_need_write = false;

    FILE* f = fopen(fname, "wb");

    for each (RowFrameData frame in m_in_frames)
    {
        fwrite(frame.data(), 1, frame.size(), f);
        fflush(f);
    }

    fclose(f);
}
#endif // _DEBUG