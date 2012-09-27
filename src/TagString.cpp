
#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>

#include "TagString.hpp"

namespace NBT {

using std::string;
using IOStream::InputStream;
using IOStream::OutputStream;

TagString::TagString(string data, string name)
    :Tag(name), data(data) {}

TagString::TagString(string name)
    :Tag(name), data("") {}

void TagString::write(OutputStream &out) const {
    out << data;
}

void TagString::read(InputStream &in) {
    in >> data;
}

string TagString::getData() const {
    return data;
}

void TagString::setData(string s) {
    data = s;
}

}

