
#include "TagDouble.hpp"

namespace NBT {

using std::string;

TagDouble::TagDouble(double d, string name)
    :Tag(name), data(d) {}

TagDouble::TagDouble(double d)
    :data(d) {}

TagDouble::TagDouble(string name)
    :Tag(name), data(0) {}

void TagDouble::write(GZipOutputStream &out) const {
    out << data;
}

void TagDouble::read(GZipInputStream &in) {
    in >> data;
}

double TagDouble::getData() const {
    return data;
}

void TagDouble::setData(double d) {
    data = d;
}

}

