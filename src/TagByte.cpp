
#include "TagByte.hpp"

namespace NBT {

using std::string;

TagByte::TagByte(uint8_t b, string name)
    :Tag(name), data(b) {}

TagByte::TagByte(uint8_t b)
    :data(b) {}

TagByte::TagByte(string name)
    :Tag(name), data(0) {}

void TagByte::write(GZipOutputStream &out) const
{
    out << data;
}

void TagByte::read(GZipInputStream &in)
{
    in >> data;
}

uint8_t TagByte::getData() const
{
    return data;
}

void TagByte::setData(uint8_t b)
{
    data = b;
}

}

