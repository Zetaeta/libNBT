
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
    void write(GZipOutputStream &) const;
    void read(GZipInputStream &);
    std::string getData() const;
    void setData(std::string);
    int getType() const {
        return 8;
    }
protected:
    std::string data;
};

}

#endif //TAGSTRING_HPP
