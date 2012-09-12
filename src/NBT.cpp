
#include "Tags.hpp"
#include "GZipInputStream.hpp"
#include "GZipOutputStream.hpp"
#include "InvalidTagId.hpp"

namespace NBT {

using std::string;

Tag & createTag(uint8_t type)
{
    switch (type)
    {
    case 0:
        return *new TagEnd();
    case 1:
        return *new TagByte();
    case 2:
        return *new TagShort();
    case 3:
        return *new TagInt();
    case 4:
        return *new TagLong();
    case 5:
        return *new TagFloat();
    case 6:
        return *new TagDouble();
    case 7:
        return *new TagByteArray();
    case 8:
        return *new TagString();
    case 9:
        return *new TagList();
    case 10:
        return *new TagCompound();
    case 11:
        return *new TagIntArray();
    default:
        throw InvalidTagId("Type ID too high!");
    }
}

Tag & createTag(uint8_t type, string name)
{
    switch (type)
    {
    case 0:
        return *new TagEnd();
    case 1:
        return *new TagByte(name);
    case 2:
        return *new TagShort(name);
    case 3:
        return *new TagInt(name);
    case 4:
        return *new TagLong(name);
    case 5:
        return *new TagFloat(name);
    case 6:
        return *new TagDouble(name);
    case 7:
        return *new TagByteArray(name);
    case 8:
        return *new TagString(name);
    case 9:
        return *new TagList(name);
    case 10:
        return *new TagCompound(name);
    case 11:
        return *new TagIntArray(name);
    default:
        throw InvalidTagId("Type ID too high!");
    }
}

void writeTag(const Tag &tag, GZipOutputStream &out)
{
    uint8_t type = tag.getType();
    out << type;
    if (type) {
        out << tag.getName();
        out << tag;
    }
}

Tag & readTag(GZipInputStream &in)
{
    uint8_t type;
    in >> type;
    if (type) {
        string name;
        in >> name;
        Tag &tag = NBT::createTag(type, name);
        in >> tag;
        return tag;
    }
    return *new TagEnd();
}

Tag & readFromFile(string filename)
{
    GZipInputStream stream(filename);
//    BigEndianInputStream stream(gzStream);
    Tag &tag = readTag(stream);
    stream.close();
    return tag;
}

void writeToFile(Tag &tag, string filename)
{
    GZipOutputStream stream(filename);
//    BigEndianOutputStream stream(gzStream);
    writeTag(tag, stream);
    stream.close();
}

}
