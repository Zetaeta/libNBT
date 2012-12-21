
#ifndef TAGBYTE_HPP
#define TAGBYTE_HPP

#include "Tag.hpp"

namespace NBT {

class TagByte : public Tag
{
public:
    TagByte() :data(0) {}
    TagByte(uint8_t, std::string);
    TagByte(uint8_t);
    TagByte(std::string);
    void write(IOStream::OutputStream &) const;
    void read(IOStream::InputStream &);
    void setData(uint8_t);
    uint8_t getData() const;
    int getType() const {
        return 1;
    }

    TagByte * clone() const;
protected:
    uint8_t data;
};

}

#endif //TAGBYTE_HPP
