
#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>

#include "TagDouble.hpp"

namespace NBT {

using std::string;
using IOStream::InputStream;
using IOStream::OutputStream;

TagDouble::TagDouble(double d, string name)
    :Tag(name), data(d) {}

TagDouble::TagDouble(double d)
    :data(d) {}

TagDouble::TagDouble(string name)
    :Tag(name), data(0) {}

void TagDouble::write(OutputStream &out) const {
    out << data;
}

void TagDouble::read(InputStream &in) {
    in >> data;
}

double TagDouble::getData() const {
    return data;
}

void TagDouble::setData(double d) {
    data = d;
}

}

