
#ifndef TAGSHORT_HPP
#define TAGSHORT_HPP

#include "Tag.hpp"

namespace NBT {

class TagShort : public Tag
{
public:
    TagShort() :data(0) {}
    TagShort(short, std::string);
    TagShort(short);
    TagShort(std::string);
    void write(IOStream::OutputStream &) const;
    void read(IOStream::InputStream &);
    short getData() const;
    void setData(short);
    int getType() const {
        return 2;
    }

    TagShort * clone() const;
protected:
    short data;
};

}

#endif //TAGSHORT_HPP
