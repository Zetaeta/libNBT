
#include "TagLong.hpp"

namespace NBT {

using std::string;

TagLong::TagLong(int64_t l, string name)
    :Tag(name), data(l) {}

TagLong::TagLong(int64_t l)
    :data(l) {}

TagLong::TagLong(string name)
    :Tag(name), data(0) {}

void TagLong::write(GZipOutputStream &out) const
{
    out << data;
}

void TagLong::read(GZipInputStream &in)
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

}

