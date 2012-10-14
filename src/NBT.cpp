
#include <sstream>

#include <IOStream/InputStream.hpp>
#include <IOStream/OutputStream.hpp>
#include <IOStream/GZipInputStream.hpp>
#include <IOStream/GZipOutputStream.hpp>
#include <IOStream/FileInputStream.hpp>
#include <IOStream/FileOutputStream.hpp>

#include "Tags.hpp"
#include "InvalidTagId.hpp"

#define GZIP_MAGIC 0x1F8B

namespace NBT {

using std::string;
using IOStream::InputStream;
using IOStream::OutputStream;
using IOStream::FileInputStream;
using IOStream::FileOutputStream;
using IOStream::GZipInputStream;
using IOStream::GZipOutputStream;
using IOStream::BIG;

Tag * createTag(uint8_t type) {
    switch (type)
    {
    case 0:
        return new TagEnd();
    case 1:
        return new TagByte();
    case 2:
        return new TagShort();
    case 3:
        return new TagInt();
    case 4:
        return new TagLong();
    case 5:
        return new TagFloat();
    case 6:
        return new TagDouble();
    case 7:
        return new TagByteArray();
    case 8:
        return new TagString();
    case 9:
        return new TagList();
    case 10:
        return new TagCompound();
    case 11:
        return new TagIntArray();
    default:
        std::ostringstream ss;
        ss << "Type ID too high: " << int(type) << '!';
        throw InvalidTagId(ss.str());
    }
}

Tag * createTag(uint8_t type, string name)
{
    switch (type)
    {
    case 0:
        return new TagEnd();
    case 1:
        return new TagByte(name);
    case 2:
        return new TagShort(name);
    case 3:
        return new TagInt(name);
    case 4:
        return new TagLong(name);
    case 5:
        return new TagFloat(name);
    case 6:
        return new TagDouble(name);
    case 7:
        return new TagByteArray(name);
    case 8:
        return new TagString(name);
    case 9:
        return new TagList(name);
    case 10:
        return new TagCompound(name);
    case 11:
        return new TagIntArray(name);
    default:
        std::ostringstream ss;
        ss << "Type ID too high: " << int(type) << '!';
        throw InvalidTagId(ss.str());
    }
}

void writeTag(const Tag &tag, OutputStream &out)
{
    uint8_t type = tag.getType();
    out << type;
    if (type) {
        out << tag.getName();
        out << tag;
    }
}

Tag * readTag(InputStream &in)
{
    uint8_t type;
    in >> type;
    if (type != 0) {
        string name;
        in >> name;
        Tag *tag = NBT::createTag(type, name);
        in >> *tag;
        return tag;
    }
    return new TagEnd();
}

Tag * readFromFile(const string &filename) {
    FileInputStream *fin = new FileInputStream(filename);
    InputStream test(fin, BIG);
    unsigned short magic = test.readUShort();
    test.close();
    if (magic == GZIP_MAGIC) {
        InputStream stream(new GZipInputStream(new FileInputStream(filename)), BIG);
        Tag *tag = readTag(stream);
        stream.close();
        return tag;
    }
    InputStream stream(new FileInputStream(filename), BIG);
    Tag *tag = readTag(stream);
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
