
#include "InputStream.hpp"

namespace NBT {

InputStream & InputStream::operator>>(int8_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}
InputStream & operator>>(uint8_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & operator>>(int16_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & operator>>(uint16_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & operator>>(int32_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & operator>>(uint32_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & operator>>(int64_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & operator>>(uint64_t &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & operator>>(float &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & operator>>(double &data) {
    read(&data, sizeof(data));
    if (!bigEndian) {
        swapEndian(data);
    }
}

InputStream & operator>>(std::string &data) {
    uint16_t length;
    operator>>(length);
    std::string s(length, 0);
    read(&s[0], length);
    data = s;
}

}

