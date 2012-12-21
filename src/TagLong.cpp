
#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>

#include "TagLong.hpp"

namespace NBT {

using std::string;
using IOStream::InputStream;
using IOStream::OutputStream;

TagLong::TagLong(int64_t l, string name)
    :Tag(name), data(l) {}

TagLong::TagLong(int64_t l)
    :data(l) {}

TagLong::TagLong(string name)
    :Tag(name), data(0) {}

void TagLong::write(OutputStream &out) const
{
    out << data;
}

void TagLong::read(InputStream &in)
{
    in >> data;
}

int64_t TagLong::getData() const
{
    return data;
}

void TagLong::setData(int64_t l)
{
    data = l;
}

TagLong * TagLong::clone() const {
    return new TagLong(data, name);
}

}

