
#ifndef INPUTSTREAM_HPP
#define INPUTSTREAM_HPP

#include <stdint.h>
#include <string>

namespace NBT {

class InputStream {
public:
    InputStream & operator>>(int8_t &);
    InputStream & operator>>(uint8_t &);
    InputStream & operator>>(int16_t &);
    InputStream & operator>>(uint16_t &);
    InputStream & operator>>(int32_t &);
    InputStream & operator>>(uint32_t &);
    InputStream & operator>>(int64_t &);
    InputStream & operator>>(uint64_t &);
    InputStream & operator>>(float &);
    InputStream & operator>>(double &);
    InputStream & operator>>(std::string &);

    virtual void * read(void *, size_t length) = 0;
    virtual void close() = 0;
};

}

#endif
