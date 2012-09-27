
#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>

#include "TagByteArray.hpp"

namespace NBT {

using std::vector;
using std::string;
using IOStream::InputStream;
using IOStream::OutputStream;

TagByteArray::TagByteArray(vector<uint8_t> b, string name)
    :Tag(name), data(b) {}

TagByteArray::TagByteArray(string name)
    :Tag(name) {}

TagByteArray::TagByteArray(vector<uint8_t> b)
    :data(b) {}

void TagByteArray::write(OutputStream &out) const
{
    out.write(data.data(), data.size());
}

void TagByteArray::read(InputStream &in)
{
    int size;
    in >> size;
//    data = vector<uint8_t>();
    data.clear();
    data.reserve(size);
    uint8_t *buf = new uint8_t[size];
    in.read(buf, size);
    for (int i=0; i<size; ++i) {
        data.push_back(buf[i]);
    }
    delete[] buf;
}

vector<uint8_t> & TagByteArray::getData()
{
    return data;
}

const vector<uint8_t> & TagByteArray::getData() const
{
    return data;
}

void TagByteArray::setData(vector<uint8_t> &v)
{
    data = v;
}

size_t TagByteArray::size() const
{
    return data.size();
}

}

