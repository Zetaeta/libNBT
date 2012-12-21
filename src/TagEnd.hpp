
#include "Tag.hpp"
#include "NBT.hpp"

#ifndef TAGEND_HPP
#define TAGLEND_HPP

namespace NBT {

class TagEnd : public Tag
{
public:
    TagEnd() {}
    void write(IOStream::OutputStream &) const {}
    void read(IOStream::InputStream &) {}
    int getType() const {
        return 0;
    }
    TagEnd * clone() const {
        return new TagEnd;
    }
};

}

#endif //TAGEND_HPP
