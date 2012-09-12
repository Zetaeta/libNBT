
#include "TagString.hpp"

namespace NBT {

using std::string;

TagString::TagString(string data, string name)
    :Tag(name), data(data) {}

TagString::TagString(string name)
    :Tag(name), data("") {}

void TagString::write(GZipOutputStream &out) const {
    out << data;
}

void TagString::read(GZipInputStream &in) {
    in >> data;
}

string TagString::getData() const {
    return data;
}

void TagString::setData(string s) {
    data = s;
}

}

