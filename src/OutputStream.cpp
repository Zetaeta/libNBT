
#include <libendian/endian.h>

#include "OutputStream.hpp"

namespace NBT {

OutputStream & OutputStream::operator<<(int8_t data) {
    toBigEndian(data);
    write(&data, sizeof(data));
}

OutputStream & OutputStream::operator<<(uint8_t) {
    toBigEndian(data);
    write(&data, sizeof(data));
}

OutputStream & OutputStream::operator<<(int16_t data) {
    toBigEndian(data);
    write(&data, sizeof(data));
}

OutputStream & OutputStream::operator<<(uint16_t data) {
    toBigEndian(data);
    write(&data, sizeof(data));
}

OutputStream & OutputStream::operator<<(int32_t data) {
    toBigEndian(data);
    write(&data, sizeof(data));
}

OutputStream & OutputStream::operator<<(uint32_t data) {
    toBigEndian(data);
    write(&data, sizeof(data));
}

OutputStream & OutputStream::operator<<(int64_t data) {
    toBigEndian(data);
    write(&data, sizeof(data));
}

OutputStream & OutputStream::operator<<(uint64_t data) {
    toBigEndian(data);
    write(&data, sizeof(data));
}

OutputStream & OutputStream::operator<<(float data) {
    toBigEndian(data);
    write(&data, sizeof(data));
}

OutputStream & OutputStream::operator<<(double data) {
    toBigEndian(data);
    write(&data, sizeof(data));
}

OutputStream & OutputStream::operator<<(const std::string &data) {
    uint16_t length(data.size());
    operator<<(length);
    write(&data[0], length);
}

}

