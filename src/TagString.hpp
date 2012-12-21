
#ifndef TAGSTRING_HPP
#define TAGSTRING_HPP

#include "Tag.hpp"

namespace NBT {

class TagString : public Tag
{
public:
    TagString() {}
    TagString(std::string, std::string);
    TagString(std::string);
    void write(IOStream::OutputStream &) const;
    void read(IOStream::InputStream &);
    std::string getData() const;
    void setData(std::string);
    int getType() const {
        return 8;
    }
    TagString * clone() const;
protected:
    std::string data;
};

}

#endif //TAGSTRING_HPP
