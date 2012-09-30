
#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>

#include "NBT.hpp"
#include "TagList.hpp"

namespace NBT {

using std::vector;
using std::string;
using IOStream::InputStream;
using IOStream::OutputStream;

TagList::TagList(const vector<Tag *> &v, const string &name)
    :Tag(name), data(v) {}

TagList::TagList(const vector<Tag *> &v)
    :data(v) {}

TagList::TagList(string name)
    :Tag(name) {}

void TagList::write(OutputStream &out) const
{
    uint8_t type;
    if (data.size() == 0) {
        type = 1;
    }
    else {
        type = data[0]->getType();
    }
    out << type;
    int size = data.size();
    out << size;
    for (int i=0; i<size; ++i) {
        data[i]->write(out);
    }
}

void TagList::read(InputStream &in)
{
    in >> type;
    int size;
    in >> size;
    data = vector<Tag *>(size);
    for (int i=0; i<size; ++i) {
        Tag *tag = NBT::createTag(type);
        in >> *tag;
        data[i] = tag;
    }
}

size_t TagList::size() const
{
    return data.size();
}

void TagList::add(Tag &tag)
{
    data.push_back(&tag);
}

void TagList::addAll(const vector<Tag *> &vec)
{
    for (vector<Tag *>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        data.push_back(*it);
    }
}

void TagList::remove(Tag &tag)
{
    for (vector<Tag *>::iterator it = data.begin(); it != data.end(); ++it) {
        if (*it == &tag) {
            data.erase(it);
        }
    }
}

void TagList::removeAll(const vector<Tag *> &vec)
{
    for (vector<Tag *>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        remove(**it);
    }
}

vector<Tag *> & TagList::getData()
{
    return data;
}

vector<Tag *> TagList::getData() const
{
    vector<Tag *> tags;
    for (vector<Tag *>::const_iterator it = data.begin(); it != data.end(); ++it) {
        tags.push_back(*it);
    }
    return tags;
}

void TagList::setData(const vector<Tag *> &data)
{
    this->data = data;
}

/*
void TagList::setData(const vector<Tag *> &data)
{
    this->data.clear();
    for (vector<Tag *>::const_iterator it = data.begin(); it != data.end(); ++it) {
        this->data.push_back(*it);
    }
}
*/

}

