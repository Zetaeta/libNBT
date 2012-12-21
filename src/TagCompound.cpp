
#include <sstream>
#include <typeinfo>
#include <memory>
#include <vector>
#include <iostream>

#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>

#include "Tags.hpp"
#include "TagNotFound.hpp"

namespace NBT {

using std::stringstream;
using std::string;
using std::map;
using std::vector;
using std::make_shared;
using std::cout;
using IOStream::InputStream;
using IOStream::OutputStream;
using std::shared_ptr;
using std::dynamic_pointer_cast;

TagCompound::TagCompound(const map<string, shared_ptr<Tag>> &v, const string &name)
:Tag(name), data(v) {}

TagCompound::TagCompound(const map<string, shared_ptr<Tag>> &v)
:data(v) {}

TagCompound::TagCompound(const string &name)
:Tag(name) {}

TagCompound::~TagCompound() {}

void TagCompound::write(OutputStream &out) const {
    for (map<string, shared_ptr<Tag>>::const_iterator it = data.begin(); it != data.end(); ++it) {
        NBT::writeTag(*it->second, out);
    }
    out << uint8_t(0);
}

void TagCompound::read(InputStream &in) {
    data.clear();
    shared_ptr<Tag>tag;
    while ((tag = NBT::readTag(in))->getType()) {
        data[tag->getName()] = tag;
    }
}

const shared_ptr<Tag> & TagCompound::get(const string &name) {
    map<string, shared_ptr<Tag>>::iterator it = data.find(name);
    if (it != data.end()) {
        return it->second;
    }
    else {
        static shared_ptr<Tag> null = nullptr;
        return null;
    }
}

int8_t TagCompound::getByte(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagByte> tb;
    if ( (tb = dynamic_pointer_cast<TagByte>(tag)) ) {
        return tb->getData();
    }
    return 0;
}

uint8_t TagCompound::getUByte(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagByte> tb;
    if ( (tb = dynamic_pointer_cast<TagByte>(tag)) ) {
        return tb->getData();
    }
    return 0;
}

short TagCompound::getShort(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagShort> ts;
    if ( (ts = dynamic_pointer_cast<TagShort>(tag)) ) {
        return ts->getData();
    }
    return 0;
}

unsigned short TagCompound::getUShort(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagShort> ts;
    if ( (ts = dynamic_pointer_cast<TagShort>(tag)) ) {
        return ts->getData();
    }
    return 0;
}

int TagCompound::getInt(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagInt> ti;
    if ( (ti = dynamic_pointer_cast<TagInt>(tag)) ) {
        return ti->getData();
    }
    return 0;
}

unsigned int TagCompound::getUInt(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagInt> ti;
    if ( (ti = dynamic_pointer_cast<TagInt>(tag)) ) {
        return ti->getData();
    }
    return 0;
}

int64_t TagCompound::getLong(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagLong> tl;
    if ( (tl = dynamic_pointer_cast<TagLong>(tag)) ) {
        return tl->getData();
    }
    return 0;
}

uint64_t TagCompound::getULong(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagLong> tl;
    if ( (tl = dynamic_pointer_cast<TagLong>(tag)) ) {
        return tl->getData();
    }
    return 0;
}

float TagCompound::getFloat(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagFloat> tf;
    if ( (tf = dynamic_pointer_cast<TagFloat>(tag)) ) {
        return tf->getData();
    }
    return 0;
}

double TagCompound::getDouble(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagDouble> td;
    if ( (td = dynamic_pointer_cast<TagDouble>(tag)) ) {
        return td->getData();
    }
    return 0;
}

string TagCompound::getString(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return "";
    }

    shared_ptr<TagString> ts;
    if ( (ts = dynamic_pointer_cast<TagString>(tag)) ) {
        return ts->getData();
    }
    return "";
}

shared_ptr<TagList> TagCompound::getList(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }

    shared_ptr<TagList> tl;
    if ( (tl = dynamic_pointer_cast<TagList>(tag)) ) {
        return tl;
    }
    throw TagNotFound(name + " is actually a " + typeid(*tl).name());
}

shared_ptr<TagCompound> TagCompound::getCompound(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }
    shared_ptr<TagCompound> ts;
    if ( (ts = dynamic_pointer_cast<TagCompound>(tag)) ) {
        return ts;
    }
    throw TagNotFound(name + " is actually a " + typeid(*ts).name());
}

vector<int> & TagCompound::getIntArray(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }

    shared_ptr<TagIntArray> tia;
    if ( (tia = dynamic_pointer_cast<TagIntArray>(tag)) ) {
        return tia->getData();
    }
    throw TagNotFound(name + " is actually a " + typeid(*tia).name());
}

vector<uint8_t> & TagCompound::getByteArray(const std::string &name) {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }

    shared_ptr<TagByteArray> tba;
    if ( (tba = dynamic_pointer_cast<TagByteArray>(tag)) ) {
        return tba->getData();
    }
    throw TagNotFound(name + " is actually a " + typeid(*tba).name());
}

const shared_ptr<Tag> TagCompound::get(const string &name) const {
    map<string, shared_ptr<Tag>>::const_iterator it = data.find(name);
    if (it != data.end()) {
        return it->second;
    }
    else {
        return 0;
    }
}

const int8_t TagCompound::getByte(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagByte> tb;
    if ( (tb = dynamic_pointer_cast<TagByte>(tag)) ) {
        return tb->getData();
    }
    return 0;
}

const uint8_t TagCompound::getUByte(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagByte> tb;
    if ( (tb = dynamic_pointer_cast<TagByte>(tag)) ) {
        return tb->getData();
    }
    return 0;
}

const short TagCompound::getShort(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagShort> ts;
    if ( (ts = dynamic_pointer_cast<TagShort>(tag)) ) {
        return ts->getData();
    }
    return 0;
}

const unsigned short TagCompound::getUShort(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagShort> ts;
    if ( (ts = dynamic_pointer_cast<TagShort>(tag)) ) {
        return ts->getData();
    }
    return 0;
}

const int TagCompound::getInt(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagInt> ti;
    if ( (ti = dynamic_pointer_cast<TagInt>(tag)) ) {
        return ti->getData();
    }
    return 0;
}

const unsigned int TagCompound::getUInt(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagInt> ti;
    if ( (ti = dynamic_pointer_cast<TagInt>(tag)) ) {
        return ti->getData();
    }
    return 0;
}

const int64_t TagCompound::getLong(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagLong> tl;
    if ( (tl = dynamic_pointer_cast<TagLong>(tag)) ) {
        return tl->getData();
    }
    return 0;
}

const uint64_t TagCompound::getULong(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagLong> tl;
    if ( (tl = dynamic_pointer_cast<TagLong>(tag)) ) {
        return tl->getData();
    }
    return 0;
}

const float TagCompound::getFloat(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagFloat> tf;
    if ( (tf = dynamic_pointer_cast<TagFloat>(tag)) ) {
        return tf->getData();
    }
    return 0;
}

const double TagCompound::getDouble(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return 0;
    }

    shared_ptr<TagDouble> td;
    if ( (td = dynamic_pointer_cast<TagDouble>(tag)) ) {
        return td->getData();
    }
    return 0;
}

const string TagCompound::getString(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        return "";
    }

    shared_ptr<TagString> ts;
    if ( (ts = dynamic_pointer_cast<TagString>(tag)) ) {
        return ts->getData();
    }
    return "";
}

shared_ptr<TagList> TagCompound::getList(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }

    shared_ptr<TagList> tl;
    if ( (tl = dynamic_pointer_cast<TagList>(tag)) ) {
        return tl;
    }
    throw TagNotFound(name + " is actually a " + typeid(*tl).name());
}

shared_ptr<TagCompound> TagCompound::getCompound(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        std::cout << "getCompound(): cannot find '" << name << "'. Contains: {";
        for (const auto p : data) {
            cout << p.first << ", ";
        }
        cout << "}\n";
        throw TagNotFound(name);
    }
    shared_ptr<TagCompound> ts;
    if ( (ts = dynamic_pointer_cast<TagCompound>(tag)) ) {
        return ts;
    }
    throw TagNotFound(name + " is actually a " + typeid(*ts).name());
}

const vector<int> & TagCompound::getIntArray(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }

    shared_ptr<TagIntArray> tia;
    if ( (tia = dynamic_pointer_cast<TagIntArray>(tag)) ) {
        return tia->getData();
    }
    throw TagNotFound(name + " is actually a " + typeid(*tia).name());
}

const vector<uint8_t> & TagCompound::getByteArray(const std::string &name) const {
    shared_ptr<Tag> tag = get(name);
    if (!tag) {
        throw TagNotFound(name);
    }

    shared_ptr<TagByteArray> tba;
    if ( (tba = dynamic_pointer_cast<TagByteArray>(tag)) ) {
        return tba->getData();
    }
    throw TagNotFound(name + " is actually a " + typeid(*tba).name());
}


void TagCompound::set(const string &name, const shared_ptr<Tag> &value) {
    value->setName(name);
    data[name] = value;
}

void TagCompound::set(const string &name, const Tag &tag) {
    shared_ptr<Tag> copy(tag.clone());
    copy->setName(name);
    data[name] = copy;
}

void TagCompound::set(const shared_ptr<Tag> &value) {
    set(value->getName(), value);
}

void TagCompound::set(const Tag &tag) {
    shared_ptr<Tag> copy(tag.clone());
    data[tag.getName()] = copy;
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

map<string, shared_ptr<Tag>> & TagCompound::getData() {
    return data;
}

const map<string, shared_ptr<Tag>> & TagCompound::getData() const {
    return data;
}

void TagCompound::set(const string &name, int8_t b) {
    set(name, make_shared<TagByte>(b, name));
}

void TagCompound::set(const string &name, uint8_t b) {
    set(name, make_shared<TagByte>(b, name));
}

void TagCompound::set(const string &name, short s) {
    set(name, make_shared<TagShort>(s, name));
}

void TagCompound::set(const string &name,unsigned short s) {
    set(name, make_shared<TagShort>(s, name));
}

void TagCompound::set(const string &name, int i) {
    set(name, make_shared<TagInt>(i, name));
}

void TagCompound::set(const string &name, unsigned int i) {
    set(name, make_shared<TagInt>(i, name));
}

void TagCompound::set(const string &name, int64_t l) {
    set(name, make_shared<TagLong>(l, name));
}

void TagCompound::set(const string &name, uint64_t l) {
    set(name, make_shared<TagLong>(l, name));
}

void TagCompound::set(const string &name, float f) {
    set(name, make_shared<TagFloat>(f, name));
}

void TagCompound::set(const string &name, double d) {
    set(name, make_shared<TagDouble>(d, name));
}

void TagCompound::set(const string &name, const vector<uint8_t> &b) {
    set(name, make_shared<TagByteArray>(b, name));
}

void TagCompound::set(const string &name, const string &s)
{
    set(name, make_shared<TagString>(s, name));
}

void TagCompound::set(const string &name, const vector<shared_ptr<Tag>> &v)
{
    set(name, make_shared<TagList>(v, name));
}

void TagCompound::set(const string &name, const map<string, shared_ptr<Tag>> &m)
{
    set(name, make_shared<TagCompound>(m, name));
}

void TagCompound::set(const string &name, const vector<int> &v)
{
    set(name, make_shared<TagIntArray>(v, name));
}

void TagCompound::setAll(const map<string, shared_ptr<Tag>> &m)
{
    for (map<string, shared_ptr<Tag>>::const_iterator it = m.begin(); it != m.end(); ++it) {
        set(it->first, it->second);
    }
}

vector<shared_ptr<Tag>> TagCompound::getChildren()
{
    vector<shared_ptr<Tag>> children;
    for (map<string, shared_ptr<Tag>>::iterator it = data.begin(); it != data.end(); ++it) {
        children.push_back(it->second);
    }
    return children;
}

TagCompound * TagCompound::clone() const {
    return new TagCompound(data, name);
}

}

