
#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>

#include "TagShort.hpp"

namespace NBT {

using std::string;
using IOStream::InputStream;
using IOStream::OutputStream;

TagShort::TagShort(short s, string name)
:Tag(name), data(s) {}

TagShort::TagShort(short s)
:data(s) {}

TagShort::TagShort(string name)
:Tag(name), data(0) {}

void TagShort::write(OutputStream &out) const {
    out << data;
}

void TagShort::read(InputStream &in) {
    in >> data;
}

short TagShort::getData() const {
    return data;
}

void TagShort::setData(short s) {
    data = s;
}

}

