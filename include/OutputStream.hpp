
#ifndef OUTPUTSTREAM_HPP
#define OUTPUTSTREAM_HPP

#include <stdint.h>
#include <string>

namespace NBT {

class OutputStream {
public:
    OutputStream & operator<<(int8_t);
    OutputStream & operator<<(uint8_t);
    OutputStream & operator<<(int16_t);
    OutputStream & operator<<(uint16_t);
    OutputStream & operator<<(int32_t);
    OutputStream & operator<<(uint32_t);
    OutputStream & operator<<(int64_t);
    OutputStream & operator<<(uint64_t);
    OutputStream & operator<<(float);
    OutputStream & operator<<(double);
    OutputStream & operator<<(const std::string &);

    virtual void write(const void *bytes, int size) = 0;
    virtual void close() = 0;
};

}

#endif // OUTPUTSTREAM_HPP
