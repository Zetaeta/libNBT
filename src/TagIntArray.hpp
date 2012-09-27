
#ifndef TAGINTARRAY_HPP
#define TAGINTARRAY_HPP

#include <vector>

#include "Tag.hpp"

namespace NBT {

class TagIntArray: public Tag
{
public:
    TagIntArray() {}
    TagIntArray(const std::vector<int> &, const std::string &);
    TagIntArray(const std::vector<int> &);
    TagIntArray(const std::string &);
    void write(IOStream::OutputStream &) const;
    void read(IOStream::InputStream &);
    const std::vector<int> & getData() const;
    std::vector<int> & getData();
    void setData(const std::vector<int> &);
    size_t size() const;
    int getType() const {
        return 11;
    }
protected:
    std::vector<int> data;
};

}

#endif
