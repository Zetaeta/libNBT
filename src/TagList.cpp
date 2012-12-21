
#include <memory>
#include <vector>

#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>

#include "NBT.hpp"
#include "TagList.hpp"

namespace NBT {

using std::vector;
using std::string;
using IOStream::InputStream;
using IOStream::OutputStream;

TagList::TagList() {
}

TagList::TagList(const vector<shared_ptr<Tag>> &v, const string &name)
    :Tag(name), data(v) {}

TagList::TagList(const vector<shared_ptr<Tag>> &v)
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
    data = vector<shared_ptr<Tag>>(size);
    for (int i=0; i<size; ++i) {
        shared_ptr<Tag> tag = NBT::createTag(type);
        in >> *tag;
        data[i] = tag;
    }
}

size_t TagList::size() const
{
    return data.size();
}

void TagList::add(const shared_ptr<Tag> &tag)
{
    data.push_back(tag);
}

void TagList::addAll(const vector<shared_ptr<Tag>> &vec)
{
    for (vector<shared_ptr<Tag>>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        data.push_back(*it);
    }
}

void TagList::remove(const shared_ptr<Tag> &tag) {
    for (vector<shared_ptr<Tag>>::iterator it = data.begin(); it != data.end(); ++it) {
        if (*it == tag) {
            data.erase(it);
        }
    }
}

void TagList::removeAll(const vector<shared_ptr<Tag>> &vec) {
    for (vector<shared_ptr<Tag>>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        remove(*it);
    }
}

shared_ptr<Tag> TagList::operator[](size_t index) {
    return data[index];
}

const shared_ptr<Tag> TagList::operator[](size_t index) const {
    return data[index];
}

vector<shared_ptr<Tag>> & TagList::getData() {
    return data;
}

const vector<shared_ptr<Tag>> & TagList::getData() const {
    return data;
}

void TagList::setData(const vector<shared_ptr<Tag>> &data) {
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

TagList * TagList::clone() const {
    return new TagList(data, name);
}

}

