
#ifndef TAGFLOAT_HPP
#define TAGFLOAT_HPP

#include "Tag.hpp"

namespace NBT {

class TagFloat : public Tag
{
public:
    TagFloat() :data(0) {}
    TagFloat(float, std::string);
    TagFloat(float);
    TagFloat(std::string);
    void write(IOStream::OutputStream &) const;
    void read(IOStream::InputStream &);
    float getData() const;
    void setData(float);
    int getType() const {
        return 5;
    }
    TagFloat * clone() const;
protected:
    float data;
};

}

#endif //TAGFLOAT_HPP
