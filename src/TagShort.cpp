
#include "TagShort.hpp"

namespace NBT {

using std::string;

TagShort::TagShort(short s, string name)
    :Tag(name), data(s) {}

TagShort::TagShort(short s)
    :data(s) {}

TagShort::TagShort(string name)
    :Tag(name), data(0) {}

void TagShort::write(GZipOutputStream &out) const
{
    out << data;
}

void TagShort::read(GZipInputStream &in)
{
    in >> data;
}

short TagShort::getData() const
{
    return data;
}

void TagShort::setData(short s)
{
    data = s;
}

}

