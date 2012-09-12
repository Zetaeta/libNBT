
#include "TagInt.hpp"

namespace NBT {

using std::string;

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

void TagInt::write(GZipOutputStream &out) const {
    out << data;
}

void TagInt::read(GZipInputStream &in) {
    in >> data;
}

int TagInt::getData() const {
    return data;
}

void TagInt::setData(int i) {
    data = i;
}

}

