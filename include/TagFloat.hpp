
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
    void write(GZipOutputStream &) const;
    void read(GZipInputStream &);
    float getData() const;
    void setData(float);
    int getType() const {
        return 5;
    }
protected:
    float data;
};

}

#endif //TAGFLOAT_HPP
