
#ifndef TAGCOMPOUND_HPP
#define TAGCOMPOUND_HPP

#include <map>
#include <vector>
#include <string>

#include "Tag.hpp"

namespace NBT {

class TagList;

class TagCompound : public Tag
{
public:
    TagCompound() {}
    TagCompound(std::map<std::string, Tag *>, std::string);
    TagCompound(std::string);
    TagCompound(std::map<std::string, Tag *>);
    ~TagCompound();
    void write(IOStream::OutputStream &) const;
    void read(IOStream::InputStream &);

    Tag * get(const std::string &);
    int8_t getByte(const std::string &);
    uint8_t getUByte(const std::string &);
    short getShort(const std::string &);
    unsigned short getUShort(const std::string &);
    int getInt(const std::string &);
    unsigned int getUInt(const std::string &);
    int64_t getLong(const std::string &);
    uint64_t getULong(const std::string &);
    float getFloat(const std::string &);
    double getDouble(const std::string &);
    std::string getString(const std::string &);
    TagList & getList(const std::string &);
    TagCompound & getCompound(const std::string &);
    std::vector<int> & getIntArray(const std::string &);
    std::vector<uint8_t> & getByteArray(const std::string &);

    const Tag * get(const std::string &) const;
    const int8_t getByte(const std::string &) const;
    const uint8_t getUByte(const std::string &) const;
    const short getShort(const std::string &) const;
    const unsigned short getUShort(const std::string &) const;
    const int getInt(const std::string &) const;
    const unsigned int getUInt(const std::string &) const;
    const int64_t getLong(const std::string &) const;
    const uint64_t getULong(const std::string &) const;
    const float getFloat(const std::string &) const;
    const double getDouble(const std::string &) const;
    const std::string getString(const std::string &) const;
    const TagList & getList(const std::string &) const;
    const TagCompound & getCompound(const std::string &) const;
    const std::vector<int> & getIntArray(const std::string &) const;
    const std::vector<uint8_t> & getByteArray(const std::string &) const;
 
    
    void set(const std::string &, Tag &);
    void set(const std::string &, Tag *);

    void set(Tag &);
    void set(Tag *);

    void set(const std::string &, uint8_t);
    void set(const std::string &, int8_t);
    void set(const std::string &, short);
    void set(const std::string &, unsigned short);
    void set(const std::string &, int);
    void set(const std::string &, unsigned int);
    void set(const std::string &, int64_t);
    void set(const std::string &, uint64_t);
    void set(const std::string &, float);
    void set(const std::string &, double);
    void set(const std::string &, const std::vector<uint8_t> &);
    void set(const std::string &, const std::string &);
    void set(const std::string &, const std::vector<int> &);
    void set(const std::string &, const std::vector<Tag *> &);
    void set(const std::string &, const std::map<std::string, Tag *> &);
    void setAll(const std::map<std::string, Tag *> &);

    size_t size() const;

    int getType() const {
        return 10;
    }
    std::string toString() const;
    std::map<std::string, Tag *> & getData();
    void setData(std::map<std::string, Tag *>);
    const std::map<std::string, Tag *> & getData() const;

    std::vector<Tag *> getChildren();
protected:
    std::map<std::string, Tag *> data;
};

}

#endif //TAGCOMPOUND_HPP
