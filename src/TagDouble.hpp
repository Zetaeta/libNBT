
#ifndef TAGDOUBLE_HPP
#define TAGDOUBLE_HPP

#include "Tag.hpp"

namespace NBT {

class TagDouble : public Tag
{
public:
    TagDouble() :data(0) {}
    TagDouble(double, std::string);
    TagDouble(double);
    TagDouble(std::string);
    void write(IOStream::OutputStream &) const;
    void read(IOStream::InputStream &);
    double getData() const;
    void setData(double);
    int getType() const {
        return 6;
    }
protected:
    double data;
};

}

#endif //TAGDOUBLE_HPP
