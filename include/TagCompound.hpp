
#ifndef TAGCOMPOUND_HPP
#define TAGCOMPOUND_HPP

#include <map>
#include <vector>
#include <string>

#include "Tag.hpp"

namespace NBT {

class TagCompound : public Tag
{
public:
    TagCompound() {}
    TagCompound(std::map<std::string, Tag *>, std::string);
    TagCompound(std::string);
    TagCompound(std::map<std::string, Tag *>);
    ~TagCompound();
    void write(GZipOutputStream &) const;
    void read(GZipInputStream &);
    Tag & get(std::string);
    
    void set(const std::string &, Tag &);
    void set(const std::string &, Tag *);

    void set(Tag &);
    void set(Tag *);

    void set(const std::string &, uint8_t);
    void set(const std::string &, short);
    void set(const std::string &, int);
    void set(const std::string &, int64_t);
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
