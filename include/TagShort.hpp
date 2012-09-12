
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
    void write(GZipOutputStream &) const;
    void read(GZipInputStream &);
    short getData() const;
    void setData(short);
    int getType() const {
        return 2;
    }
protected:
    short data;
};

}

#endif //TAGSHORT_HPP
