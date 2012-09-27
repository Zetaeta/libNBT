
#ifndef NBT_HPP
#define NBT_HPP

#include <string>
#include <stdint.h>

namespace IOStream {
class OutputStream;
class InputStream;
}

namespace NBT {

class Tag;

Tag * createTag(uint8_t);
Tag * createTag(uint8_t, std::string);
void writeTag(const Tag &, IOStream::OutputStream &);
Tag * readTag(IOStream::InputStream &);
void writeToFile(const Tag &tag, const std::string &);
Tag *readFromFile(const std::string &);

}

#endif
