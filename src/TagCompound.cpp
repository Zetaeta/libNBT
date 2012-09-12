
#include "Tags.hpp"
#include <sstream>

namespace NBT {

using std::stringstream;
using std::string;
using std::map;
using std::vector;

TagCompound::TagCompound(map<string, Tag *> v, string name)
:Tag(name), data(v) {}

TagCompound::TagCompound(map<string, Tag *> v)
:data(v) {}

TagCompound::TagCompound(string name)
:Tag(name) {}

TagCompound::~TagCompound() {}

void TagCompound::write(GZipOutputStream &out) const {
    for (map<string, Tag *>::const_iterator it = data.begin(); it != data.end(); ++it) {
        NBT::writeTag(*it->second, out);
    }
    out << uint8_t(0);
}

void TagCompound::read(GZipInputStream &in) {
    data.clear();
    Tag *tag;
    while ((tag = &NBT::readTag(in))->getType()) {
        data[tag->getName()] = tag;
    }
}

Tag & TagCompound::get(string name) {
    return *(data[name]);
}

void TagCompound::set(const string &name, Tag &value) {
    value.setName(name);
    data[name] = &value;
}

void TagCompound::set(const string &name, Tag *value) {
    value->setName(name);
    data[name] = value;
}

void TagCompound::set(Tag &value) {
    set(value.getName(), value);
}

void TagCompound::set(Tag *value) {
    set(value->getName(), value);
}

size_t TagCompound::size() const {
    return data.size();
}

string TagCompound::toString() const {
    static string name = "TagCompound";
    stringstream ss;
    ss << name << '{';
    for (auto it = data.begin(); it != data.end(); ++it) {
        ss << "[" << (*it).first << "=" << (*it).second->getType() << "], ";
    }
    ss << '}';
    return ss.str();
}

map<string, Tag *> & TagCompound::getData() {
    return data;
}

const map<string, Tag *> & TagCompound::getData() const
{
//    map<string, Tag *> m;
//    for (map<string, Tag *>::const_iterator it = data.begin(); it != data.end(); ++it) {
//        m[it->first] = it->second.toPtr();
//    }
    return data;
}

void TagCompound::set(const string &name, uint8_t b)
{
    set(name, new TagByte(b, name));
}

void TagCompound::set(const string &name, short s)
{
    set(name, new TagShort(s, name));
}

void TagCompound::set(const string &name, int i)
{
    set(name, new TagInt(i, name));
}

void TagCompound::set(const string &name, int64_t l)
{
    set(name, new TagLong(l, name));
}

void TagCompound::set(const string &name, float f)
{
    set(name, new TagFloat(f, name));
}

void TagCompound::set(const string &name, double d)
{
    set(name, new TagDouble(d, name));
}

void TagCompound::set(const string &name, const vector<uint8_t> &b)
{
    set(name, new TagByteArray(b, name));
}

void TagCompound::set(const string &name, const string &s)
{
    set(name, new TagString(s, name));
}

void TagCompound::set(const string &name, const vector<Tag *> &v)
{
    set(name, new TagList(v, name));
}

void TagCompound::set(const string &name, const map<string, Tag *> &m)
{
    set(name, new TagCompound(m, name));
}

void TagCompound::set(const string &name, const vector<int> &v)
{
    set(name, new TagIntArray(v, name));
}

void TagCompound::setAll(const map<string, Tag *> &m)
{
    for (map<string, Tag *>::const_iterator it = m.begin(); it != m.end(); ++it) {
        set(it->first, it->second);
    }
}

vector<Tag *> TagCompound::getChildren()
{
    vector<Tag *> children;
    for (map<string, Tag *>::iterator it = data.begin(); it != data.end(); ++it) {
        children.push_back(&(*((*it).second)));
    }
    return children;
}

}

