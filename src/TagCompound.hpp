
#ifndef TAGCOMPOUND_HPP
#define TAGCOMPOUND_HPP

#include <map>
#include <vector>
#include <string>

#include <Util/stlfwd.hpp>

#include "Tag.hpp"

namespace NBT {

class TagList;

using std::shared_ptr;
using std::vector;
using std::map;
using std::string;

class TagCompound : public Tag
{
public:
    TagCompound() {}
    TagCompound(const map<string, shared_ptr<Tag>> &, const string &);
    TagCompound(const string &);
    TagCompound(const map<string, shared_ptr<Tag>> &);
    ~TagCompound();
    void write(IOStream::OutputStream &) const;
    void read(IOStream::InputStream &);

    const shared_ptr<Tag> & get(const string &);
    int8_t getByte(const string &);
    uint8_t getUByte(const string &);
    short getShort(const string &);
    unsigned short getUShort(const string &);
    int getInt(const string &);
    unsigned int getUInt(const string &);
    int64_t getLong(const string &);
    uint64_t getULong(const string &);
    float getFloat(const string &);
    double getDouble(const string &);
    string getString(const string &);
    shared_ptr<TagList> getList(const string &);
    shared_ptr<TagCompound> getCompound(const string &);
    vector<int> & getIntArray(const string &);
    vector<uint8_t> & getByteArray(const string &);

    const shared_ptr<Tag> get(const string &) const;
    const int8_t getByte(const string &) const;
    const uint8_t getUByte(const string &) const;
    const short getShort(const string &) const;
    const unsigned short getUShort(const string &) const;
    const int getInt(const string &) const;
    const unsigned int getUInt(const string &) const;
    const int64_t getLong(const string &) const;
    const uint64_t getULong(const string &) const;
    const float getFloat(const string &) const;
    const double getDouble(const string &) const;
    const string getString(const string &) const;
    shared_ptr<TagList> getList(const string &) const;
    shared_ptr<TagCompound> getCompound(const string &) const;
    const vector<int> & getIntArray(const string &) const;
    const vector<uint8_t> & getByteArray(const string &) const;
 
    
    void set(const string &, const shared_ptr<Tag> &);
    void set(const string &, const Tag &);

    void set(const shared_ptr<Tag> &);
    void set(const Tag &);

    void set(const string &, uint8_t);
    void set(const string &, int8_t);
    void set(const string &, short);
    void set(const string &, unsigned short);
    void set(const string &, int);
    void set(const string &, unsigned int);
    void set(const string &, int64_t);
    void set(const string &, uint64_t);
    void set(const string &, float);
    void set(const string &, double);
    void set(const string &, const vector<uint8_t> &);
    void set(const string &, const string &);
    void set(const string &, const vector<int> &);
    void set(const string &, const vector<shared_ptr<Tag>> &);
    void set(const string &, const map<string, shared_ptr<Tag>> &);
    void setAll(const map<string, shared_ptr<Tag>> &);

    size_t size() const;

    int getType() const {
        return 10;
    }
    string toString() const;
    map<string, shared_ptr<Tag>> & getData();
    void setData(map<string, shared_ptr<Tag>>);
    const map<string, shared_ptr<Tag>> & getData() const;

    vector<shared_ptr<Tag>> getChildren();
    TagCompound * clone() const;
protected:
    map<string, shared_ptr<Tag>> data;
};

}

#endif //TAGCOMPOUND_HPP
