
#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>

#include "TagInt.hpp"

namespace NBT {

using std::string;
using IOStream::InputStream;
using IOStream::OutputStream;

TagInt::TagInt(int i, string name)
:Tag(name), data(i) {
}

TagInt::TagInt(int i)
:data(i) {}

TagInt::TagInt(string name)
:Tag(name), data(0) {}

TagInt::TagInt(const TagInt &other)
:Tag(other), data(other.data) {
}

void TagInt::write(OutputStream &out) const {
    out << data;
}

void TagInt::read(InputStream &in) {
    in >> data;
}

int TagInt::getData() const {
    return data;
}

void TagInt::setData(int i) {
    data = i;
}

}

