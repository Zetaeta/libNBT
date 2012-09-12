
#include "TagIntArray.hpp"

namespace NBT {

using std::vector;
using std::string;

TagIntArray::TagIntArray(const vector<int> &b, const string &name)
    :Tag(name), data(b) {}

TagIntArray::TagIntArray(const string &name)
    :Tag(name) {}

TagIntArray::TagIntArray(const vector<int> &b)
    :data(b) {}

void TagIntArray::write(GZipOutputStream &out) const
{
    out << int(data.size());
    for (int i=0; i<data.size(); ++i) {
        out << data[i];
    }
}

void TagIntArray::read(GZipInputStream &in)
{
    int size;
    in >> size;
    data = vector<int>(size);
    for (int i=0; i<size; ++i) {
        in >> data[i];
    }
}

vector<int> & TagIntArray::getData()
{
    return data;
}

const vector<int> & TagIntArray::getData() const
{
    return data;
}

void TagIntArray::setData(const vector<int> &v)
{
    data = v;
}

size_t TagIntArray::size() const
{
    return data.size();
}

}

