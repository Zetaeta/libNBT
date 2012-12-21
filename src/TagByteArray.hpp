
#ifndef TAGBYTEARRAY_HPP
#define TAGBYTEARRAY_HPP

#include <vector>

#include "Tag.hpp"

namespace NBT {

class TagByteArray: public Tag
{
public:
    TagByteArray() {}
    TagByteArray(std::vector<uint8_t>, std::string);
    TagByteArray(std::vector<uint8_t>);
    TagByteArray(std::string);
    TagByteArray(uint8_t *, size_t, std::string = "");
    void write(IOStream::OutputStream &) const;
    void read(IOStream::InputStream &);
    std::vector<uint8_t> & getData();
    const std::vector<uint8_t> & getData() const;
    void setData(std::vector<uint8_t> &);
    size_t size() const;
    int getType() const {
        return 7;
    }
    TagByteArray * clone() const;
protected:
    std::vector<uint8_t> data;
};

}

#endif
