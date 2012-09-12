
#ifndef TAG_HPP
#define TAG_HPP

#include <string>
#include "GZipOutputStream.hpp"
#include "GZipInputStream.hpp"

namespace NBT {

class Tag {
public:
    Tag();
    explicit Tag(std::string);
    virtual void write(GZipOutputStream &) const = 0;
    virtual void read(GZipInputStream &) = 0;
    virtual std::string getName() const;
    virtual void setName(std::string);
    virtual int getType() const = 0;
protected:
    std::string name;
};

inline GZipOutputStream & operator<<(GZipOutputStream &out, const Tag &tag) {
    tag.write(out);
    return out;
}

inline GZipInputStream & operator>>(GZipInputStream &in, Tag &tag) {
    tag.read(in);
    return in;
}

}

#endif // TAG_HPP
