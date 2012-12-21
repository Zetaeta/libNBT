
#include <sstream>
#include <memory>
#include <vector>
#include <iostream>

#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>
#include <IOStream/GZipInputStream.hpp>
#include <IOStream/GZipOutputStream.hpp>
#include <IOStream/FileInputStream.hpp>
#include <IOStream/FileOutputStream.hpp>

#include <Util/Throw.hpp>

#include "Tags.hpp"
#include "InvalidTagId.hpp"

#define GZIP_MAGIC 0x1F8B

namespace NBT {

using std::string;
using std::shared_ptr;
using std::make_shared;
using std::cout;
using IOStream::InputStream;
using IOStream::OutputStream;
using IOStream::FileInputStream;
using IOStream::FileOutputStream;
using IOStream::GZipInputStream;
using IOStream::GZipOutputStream;
using IOStream::BIG;

const std::string tagTypeNames[12] = {
    "TagEnd",
    "TagByte",
    "TagShort",
    "TagInt",
    "TagLong",
    "TagFloat",
    "TagDouble",
    "TagByteArray",
    "TagString",
    "TagList",
    "TagCompound",
    "TagIntArray"
};

const std::string & tagTypeName(uint8_t type) {
    if (type > 11) {
        std::ostringstream oss;
        oss << uint16_t(type);
        throwSpecific(InvalidTagId, oss.str());
    }
    return tagTypeNames[type];
}

shared_ptr<Tag> createTag(uint8_t type) {
    switch (type)
    {
    case 0:
        return make_shared<TagEnd>();
    case 1:
        return make_shared<TagByte>();
    case 2:
        return make_shared<TagShort>();
    case 3:
        return make_shared<TagInt>();
    case 4:
        return make_shared<TagLong>();
    case 5:
        return make_shared<TagFloat>();
    case 6:
        return make_shared<TagDouble>();
    case 7:
        return make_shared<TagByteArray>();
    case 8:
        return make_shared<TagString>();
    case 9:
        return make_shared<TagList>();
    case 10:
        return make_shared<TagCompound>();
    case 11:
        return make_shared<TagIntArray>();
    default:
        std::ostringstream ss;
        ss << "Type ID too high: " << int(type) << '!';
        throw InvalidTagId(ss.str());
    }
}

shared_ptr<Tag> createTag(uint8_t type, string name)
{
    switch (type)
    {
    case 0:
        return make_shared<TagEnd>();
    case 1:
        return make_shared<TagByte>(name);
    case 2:
        return make_shared<TagShort>(name);
    case 3:
        return make_shared<TagInt>(name);
    case 4:
        return make_shared<TagLong>(name);
    case 5:
        return make_shared<TagFloat>(name);
    case 6:
        return make_shared<TagDouble>(name);
    case 7:
        return make_shared<TagByteArray>(name);
    case 8:
        return make_shared<TagString>(name);
    case 9:
        return make_shared<TagList>(name);
    case 10:
        return make_shared<TagCompound>(name);
    case 11:
        return make_shared<TagIntArray>(name);
    default:
        std::ostringstream ss;
        ss << "Type ID too high: " << int(type) << '!';
        throw InvalidTagId(ss.str());
    }
}

void writeTag(const Tag &tag, OutputStream &out)
{
    uint8_t type = tag.getType();
//    cout << "NBT::writeTag(): writing tag " << tag.getName() << " of type " << tagTypeName(tag.getType()) << '\n';
    out << type;
    if (type) {
        out << tag.getName();
        out << tag;
    }
}

shared_ptr<Tag> readTag(InputStream &in)
{
    uint8_t type;
    in >> type;
    if (type != 0) {
        string name;
        in >> name;
//        std::cout << "NBT::readTag(): name = " << name << ", type = " << tagTypeName(type) << '\n';
        shared_ptr<Tag> tag = NBT::createTag(type, name);
        in >> *tag;
        return tag;
    }
    return make_shared<TagEnd>();
}

shared_ptr<Tag> readFromFile(const string &filename) {
    FileInputStream *fin = new FileInputStream(filename);
    InputStream test(fin, BIG);
    unsigned short magic = test.readUShort();
    test.close();
    if (magic == GZIP_MAGIC) {
        InputStream stream(new GZipInputStream(new FileInputStream(filename)), BIG);
        shared_ptr<Tag> tag = readTag(stream);
        stream.close();
        return tag;
    }
    InputStream stream(new FileInputStream(filename), BIG);
    shared_ptr<Tag> tag = readTag(stream);
    stream.close();
    return tag;
}

void writeToFile(const Tag &tag, const string &filename, bool compressed)
{
    if (compressed) {
        OutputStream stream(new GZipOutputStream(filename), BIG);
        writeTag(tag, stream);
        stream.close();
    }
    else {
        OutputStream stream(new FileOutputStream(filename), BIG);
        writeTag(tag, stream);
        stream.close();
    }
}

}
