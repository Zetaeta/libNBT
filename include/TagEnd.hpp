
#include "Tag.hpp"
#include "NBT.hpp"

#ifndef TAGEND_HPP
#define TAGLEND_HPP

namespace NBT {

class TagEnd : public Tag
{
public:
    TagEnd() {}
    void write(GZipOutputStream &) const {}
    void read(GZipInputStream &) {}
    int getType() const {
        return 0;
    }
};

}

#endif //TAGEND_HPP
