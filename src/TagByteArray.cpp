
#include "TagByteArray.hpp"

namespace NBT {

using std::vector;
using std::string;

TagByteArray::TagByteArray(vector<uint8_t> b, string name)
    :Tag(name), data(b) {}

TagByteArray::TagByteArray(string name)
    :Tag(name) {}

TagByteArray::TagByteArray(vector<uint8_t> b)
    :data(b) {}

void TagByteArray::write(GZipOutputStream &out) const
{
    out.write(data.data(), data.size());
}

void TagByteArray::read(GZipInputStream &in)
{
    int size;
    in >> size;
    data = vector<uint8_t>(size);
    uint8_t *newData = static_cast<uint8_t *>(in.read(NULL, size));
    for (int i=0; i<size; ++i) {
        data.push_back(newData[i]);
    }
    delete[] newData;
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

