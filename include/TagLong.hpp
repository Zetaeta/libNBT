
#ifndef TAGLONG_HPP
#define TAGLONG_HPP

#include "Tag.hpp"

namespace NBT {

class TagLong : public Tag
{
public:
    TagLong() :data(0) {}
    TagLong(int64_t, std::string);
    TagLong(int64_t);
    TagLong(std::string);
    void write(GZipOutputStream &) const;
    void read(GZipInputStream &);
    int64_t getData() const;
    void setData(int64_t);
    int getType() const {
        return 4;
    }
protected:
    int64_t data;
};

}

#endif //TAGLONG_HPP
