
#ifndef TAG_HPP
#define TAG_HPP

#include <string>

namespace IOStream {
class InputStream;
class OutputStream;
}

namespace NBT {

class Tag {
public:
    Tag();
    explicit Tag(std::string);
    virtual void write(IOStream::OutputStream &) const = 0;
    virtual void read(IOStream::InputStream &) = 0;
    virtual std::string getName() const;
    virtual void setName(std::string);
    virtual int getType() const = 0;
protected:
    std::string name;
};

inline IOStream::OutputStream & operator<<(IOStream::OutputStream &out, const Tag &tag) {
    tag.write(out);
    return out;
}

inline IOStream::InputStream & operator>>(IOStream::InputStream &in, Tag &tag) {
    tag.read(in);
    return in;
}

}

#endif // TAG_HPP
