
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
    void write(GZipOutputStream &) const;
    void read(GZipInputStream &);
    std::vector<uint8_t> & getData();
    const std::vector<uint8_t> & getData() const;
    void setData(std::vector<uint8_t> &);
    size_t size() const;
    int getType() const {
        return 7;
    }
protected:
    std::vector<uint8_t> data;
};

}

#endif
