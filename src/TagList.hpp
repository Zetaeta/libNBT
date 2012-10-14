
#ifndef TAGLIST_HPP
#define TAGLIST_HPP

#include <vector>

#include "Tag.hpp"

namespace NBT {

class TagList : public Tag
{
public:
    TagList() {}
    TagList(std::string);
    TagList(const std::vector<Tag *> &);
    TagList(const std::vector<Tag *> &, const std::string &);
    void write(IOStream::OutputStream &) const;
    void read(IOStream::InputStream &);
    size_t size() const;

    void add(Tag &);
    void remove(Tag &);
    void addAll(const std::vector<Tag *> &);
    void removeAll(const std::vector<Tag *> &);

    Tag * operator[](size_t);
    const Tag * operator[](size_t) const;
    std::vector<Tag *> & getData();
    const std::vector<Tag *> & getData() const;
    void setData(const std::vector<Tag *> &);
    int getType() const {
        return 9;
    }
protected:
    std::vector<Tag *> data;
    uint8_t type;
};

}

#endif //TAGLIST_HPP
