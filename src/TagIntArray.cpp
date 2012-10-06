
#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>

#include "TagIntArray.hpp"

namespace NBT {

using std::vector;
using std::string;
using IOStream::InputStream;
using IOStream::OutputStream;

TagIntArray::TagIntArray(const vector<int> &b, const string &name)
    :Tag(name), data(b) {}

TagIntArray::TagIntArray(const string &name)
    :Tag(name) {}

TagIntArray::TagIntArray(const vector<int> &b)
    :data(b) {}

void TagIntArray::write(OutputStream &out) const
{
    out << int(data.size());
    for (size_t i=0; i<data.size(); ++i) {
        out << data[i];
    }
}

void TagIntArray::read(InputStream &in)
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

