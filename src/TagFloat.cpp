
#include "TagFloat.hpp"

namespace NBT {

using std::string;

TagFloat::TagFloat(float f, string name)
    :Tag(name), data(f) {}

TagFloat::TagFloat(float f)
    :data(f) {}

TagFloat::TagFloat(string name)
    :Tag(name), data(0.0F) {}

void TagFloat::write(GZipOutputStream &out) const
{
    out << data;
}

void TagFloat::read(GZipInputStream &in)
{
    in >> data;
}

float TagFloat::getData() const
{
    return data;
}

void TagFloat::setData(float f)
{
    data = f;
}

}

