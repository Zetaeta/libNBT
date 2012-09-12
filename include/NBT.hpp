
#ifndef NBT_HPP
#define NBT_HPP

#include <string>
#include <stdint.h>

namespace NBT {

class GZipOutputStream;
class GZipInputStream;

class Tag;

Tag & createTag(uint8_t);
Tag & createTag(uint8_t, std::string);
void writeTag(const Tag &, GZipOutputStream &);
Tag & readTag(GZipInputStream &);
void writeToFile(std::string, Tag &);

}

#endif
