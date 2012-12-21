
#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>

#include "TagByte.hpp"

namespace NBT {

using std::string;
using IOStream::InputStream;
using IOStream::OutputStream;

TagByte::TagByte(uint8_t b, string name)
    :Tag(name), data(b) {}

TagByte::TagByte(uint8_t b)
    :data(b) {}

TagByte::TagByte(string name)
    :Tag(name), data(0) {}

void TagByte::write(OutputStream &out) const
{
    out << data;
}

void TagByte::read(InputStream &in)
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

TagByte * TagByte::clone() const {
    return new TagByte(data, name);
}

}

