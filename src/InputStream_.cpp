
#include <sstream>

#include <libendian/endian.h>

#include "InputStream.hpp"

namespace NBT {

InputStream & InputStream::operator>>(int8_t &data) {
    read(&data, sizeof(data));
}
InputStream & InputStream::operator>>(uint8_t &data) {
    read(&data, sizeof(data));
}

InputStream & InputStream::operator>>(int16_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & InputStream::operator>>(uint16_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & InputStream::operator>>(int32_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & InputStream::operator>>(uint32_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & InputStream::operator>>(int64_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & InputStream::operator>>(uint64_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & InputStream::operator>>(float &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & InputStream::operator>>(double &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & InputStream::operator>>(std::string &data) {
    uint16_t length;
    operator>>(length);
    std::stringstream ss;
    for (int i=0; i<length; ++i) {
        char ch;
        read(&ch, 1);
        ss << ch;
    }
    data = ss.str();
}

}

