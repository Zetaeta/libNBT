
#ifndef TAGLIST_HPP
#define TAGLIST_HPP

#include <vector>
#include <memory>

#include "Tag.hpp"

namespace NBT {

using std::shared_ptr;

class TagList : public Tag
{
public:
    TagList();
    TagList(std::string);
    TagList(const std::vector<shared_ptr<Tag>> &);
    TagList(const std::vector<shared_ptr<Tag>> &, const std::string &);
    void write(IOStream::OutputStream &) const;
    void read(IOStream::InputStream &);
    size_t size() const;

    void add(const shared_ptr<Tag> &);
    void remove(const shared_ptr<Tag> &);
    void addAll(const std::vector<shared_ptr<Tag>> &);
    void removeAll(const std::vector<shared_ptr<Tag>> &);

    shared_ptr<Tag> operator[](size_t);
    const shared_ptr<Tag> operator[](size_t) const;
    std::vector<shared_ptr<Tag>> & getData();
    const std::vector<shared_ptr<Tag>> & getData() const;
    void setData(const std::vector<shared_ptr<Tag>> &);
    int getType() const {
        return 9;
    }
    TagList * clone() const;
protected:
    std::vector<shared_ptr<Tag>> data;
    uint8_t type;
};

}

#endif //TAGLIST_HPP
