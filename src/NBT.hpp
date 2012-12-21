
#ifndef NBT_HPP
#define NBT_HPP

#include <string>
#include <stdint.h>

#include <Util/stlfwd.hpp>

namespace IOStream {
class OutputStream;
class InputStream;
}

namespace NBT {

using std::shared_ptr;

class Tag;

shared_ptr<Tag> createTag(uint8_t);
shared_ptr<Tag> createTag(uint8_t, std::string);
void writeTag(const Tag &, IOStream::OutputStream &);
shared_ptr<Tag> readTag(IOStream::InputStream &);
void writeToFile(const Tag &tag, const std::string &);
shared_ptr<Tag>readFromFile(const std::string &);

}

#endif
