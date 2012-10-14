
#include <sstream>
#include <typeinfo>

#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>

#include "Tags.hpp"
#include "TagNotFound.hpp"

namespace NBT {

using std::stringstream;
using std::string;
using std::map;
using std::vector;
using IOStream::InputStream;
using IOStream::OutputStream;

TagCompound::TagCompound(map<string, Tag *> v, string name)
:Tag(name), data(v) {}

TagCompound::TagCompound(map<string, Tag *> v)
:data(v) {}

TagCompound::TagCompound(string name)
:Tag(name) {}

TagCompound::~TagCompound() {}

void TagCompound::write(OutputStream &out) const {
    for (map<string, Tag *>::const_iterator it = data.begin(); it != data.end(); ++it) {
        NBT::writeTag(*it->second, out);
    }
    out << uint8_t(0);
}

void TagCompound::read(InputStream &in) {
    data.clear();
    Tag *tag;
    while ((tag = NBT::readTag(in))->getType()) {
        data[tag->getName()] = tag;
    }
}

Tag * TagCompound::get(const string &name) {
    map<string, Tag *>::iterator it = data.find(name);
    if (it != data.end()) {
        return it->second;
    }
    else {
        return 0;
    }
}

int8_t TagCompound::getByte(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    TagByte *tb;
    if ( (tb = dynamic_cast<TagByte *>(tag)) ) {
        return tb->getData();
    }
    return 0;
}

uint8_t TagCompound::getUByte(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    TagByte *tb;
    if ( (tb = dynamic_cast<TagByte *>(tag)) ) {
        return tb->getData();
    }
    return 0;
}

short TagCompound::getShort(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    TagShort *ts;
    if ( (ts = dynamic_cast<TagShort *>(tag)) ) {
        return ts->getData();
    }
    return 0;
}

unsigned short TagCompound::getUShort(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    TagShort *ts;
    if ( (ts = dynamic_cast<TagShort *>(tag)) ) {
        return ts->getData();
    }
    return 0;
}

int TagCompound::getInt(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    TagInt *ti;
    if ( (ti = dynamic_cast<TagInt *>(tag)) ) {
        return ti->getData();
    }
    return 0;
}

unsigned int TagCompound::getUInt(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    TagInt *ti;
    if ( (ti = dynamic_cast<TagInt *>(tag)) ) {
        return ti->getData();
    }
    return 0;
}

int64_t TagCompound::getLong(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    TagLong *tl;
    if ( (tl = dynamic_cast<TagLong *>(tag)) ) {
        return tl->getData();
    }
    return 0;
}

uint64_t TagCompound::getULong(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    TagLong *tl;
    if ( (tl = dynamic_cast<TagLong *>(tag)) ) {
        return tl->getData();
    }
    return 0;
}

float TagCompound::getFloat(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    TagFloat *tf;
    if ( (tf = dynamic_cast<TagFloat *>(tag)) ) {
        return tf->getData();
    }
    return 0;
}

double TagCompound::getDouble(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    TagDouble *td;
    if ( (td = dynamic_cast<TagDouble *>(tag)) ) {
        return td->getData();
    }
    return 0;
}

string TagCompound::getString(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        return "";
    }

    TagString *ts;
    if ( (ts = dynamic_cast<TagString *>(tag)) ) {
        return ts->getData();
    }
    return "";
}

TagList & TagCompound::getList(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }

    TagList *tl;
    if ( (tl = dynamic_cast<TagList *>(tag)) ) {
        return *tl;
    }
    throw TagNotFound(name + " is actually a " + typeid(*tl).name());
}

TagCompound & TagCompound::getCompound(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }
    TagCompound *ts;
    if ( (ts = dynamic_cast<TagCompound *>(tag)) ) {
        return *ts;
    }
    throw TagNotFound(name + " is actually a " + typeid(*ts).name());
}

vector<int> & TagCompound::getIntArray(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }

    TagIntArray *tia;
    if ( (tia = dynamic_cast<TagIntArray *>(tag)) ) {
        return tia->getData();
    }
    throw TagNotFound(name + " is actually a " + typeid(*tia).name());
}

vector<uint8_t> & TagCompound::getByteArray(const std::string &name) {
    Tag *tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }

    TagByteArray *tba;
    if ( (tba = dynamic_cast<TagByteArray *>(tag)) ) {
        return tba->getData();
    }
    throw TagNotFound(name + " is actually a " + typeid(*tba).name());
}

const Tag * TagCompound::get(const string &name) const {
    map<string, Tag *>::const_iterator it = data.find(name);
    if (it != data.end()) {
        return it->second;
    }
    else {
        return 0;
    }
}

const int8_t TagCompound::getByte(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    const TagByte *tb;
    if ( (tb = dynamic_cast<const TagByte *>(tag)) ) {
        return tb->getData();
    }
    return 0;
}

const uint8_t TagCompound::getUByte(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    const TagByte *tb;
    if ( (tb = dynamic_cast<const TagByte *>(tag)) ) {
        return tb->getData();
    }
    return 0;
}

const short TagCompound::getShort(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    const TagShort *ts;
    if ( (ts = dynamic_cast<const TagShort *>(tag)) ) {
        return ts->getData();
    }
    return 0;
}

const unsigned short TagCompound::getUShort(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    const TagShort *ts;
    if ( (ts = dynamic_cast<const TagShort *>(tag)) ) {
        return ts->getData();
    }
    return 0;
}

const int TagCompound::getInt(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    const TagInt *ti;
    if ( (ti = dynamic_cast<const TagInt *>(tag)) ) {
        return ti->getData();
    }
    return 0;
}

const unsigned int TagCompound::getUInt(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    const TagInt *ti;
    if ( (ti = dynamic_cast<const TagInt *>(tag)) ) {
        return ti->getData();
    }
    return 0;
}

const int64_t TagCompound::getLong(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    const TagLong *tl;
    if ( (tl = dynamic_cast<const TagLong *>(tag)) ) {
        return tl->getData();
    }
    return 0;
}

const uint64_t TagCompound::getULong(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    const TagLong *tl;
    if ( (tl = dynamic_cast<const TagLong *>(tag)) ) {
        return tl->getData();
    }
    return 0;
}

const float TagCompound::getFloat(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    const TagFloat *tf;
    if ( (tf = dynamic_cast<const TagFloat *>(tag)) ) {
        return tf->getData();
    }
    return 0;
}

const double TagCompound::getDouble(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        return 0;
    }

    const TagDouble *td;
    if ( (td = dynamic_cast<const TagDouble *>(tag)) ) {
        return td->getData();
    }
    return 0;
}

const string TagCompound::getString(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        return "";
    }

    const TagString *ts;
    if ( (ts = dynamic_cast<const TagString *>(tag)) ) {
        return ts->getData();
    }
    return "";
}

const TagList & TagCompound::getList(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }

    const TagList *tl;
    if ( (tl = dynamic_cast<const TagList *>(tag)) ) {
        return *tl;
    }
    throw TagNotFound(name + " is actually a " + typeid(*tl).name());
}

const TagCompound & TagCompound::getCompound(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }
    const TagCompound *ts;
    if ( (ts = dynamic_cast<const TagCompound *>(tag)) ) {
        return *ts;
    }
    throw TagNotFound(name + " is actually a " + typeid(*ts).name());
}

const vector<int> & TagCompound::getIntArray(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }

    const TagIntArray *tia;
    if ( (tia = dynamic_cast<const TagIntArray *>(tag)) ) {
        return tia->getData();
    }
    throw TagNotFound(name + " is actually a " + typeid(*tia).name());
}

const vector<uint8_t> & TagCompound::getByteArray(const std::string &name) const {
    const Tag *tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }

    const TagByteArray *tba;
    if ( (tba = dynamic_cast<const TagByteArray *>(tag)) ) {
        return tba->getData();
    }
    throw TagNotFound(name + " is actually a " + typeid(*tba).name());
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

const map<string, Tag *> & TagCompound::getData() const {
//    map<string, Tag *> m;
//    for (map<string, Tag *>::const_iterator it = data.begin(); it != data.end(); ++it) {
//        m[it->first] = it->second.toPtr();
//    }
    return data;
}

void TagCompound::set(const string &name, int8_t b) {
    set(name, new TagByte(b, name));
}

void TagCompound::set(const string &name, uint8_t b) {
    set(name, new TagByte(b, name));
}

void TagCompound::set(const string &name, short s) {
    set(name, new TagShort(s, name));
}

void TagCompound::set(const string &name,unsigned short s) {
    set(name, new TagShort(s, name));
}

void TagCompound::set(const string &name, int i) {
    set(name, new TagInt(i, name));
}

void TagCompound::set(const string &name, unsigned int i) {
    set(name, new TagInt(i, name));
}

void TagCompound::set(const string &name, int64_t l) {
    set(name, new TagLong(l, name));
}

void TagCompound::set(const string &name, uint64_t l) {
    set(name, new TagLong(l, name));
}

void TagCompound::set(const string &name, float f) {
    set(name, new TagFloat(f, name));
}

void TagCompound::set(const string &name, double d) {
    set(name, new TagDouble(d, name));
}

void TagCompound::set(const string &name, const vector<uint8_t> &b) {
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

