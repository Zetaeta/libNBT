
#ifndef TAGINT_HPP
#define TAGINT_HPP

#include "Tag.hpp"

namespace NBT {

class TagInt : public Tag
{
public:
    TagInt(const TagInt &);
    TagInt() :data(0) {}
    TagInt(int, std::string);
    TagInt(int);
    TagInt(std::string);
    void write(IOStream::OutputStream &) const;
    void read(IOStream::InputStream &);
    int getData() const;
    void setData(int);
    int getType() const {
        return 3;
    }
    TagInt * clone() const;
protected:
    int data;
};

}

#endif //TAGINT_HPP
