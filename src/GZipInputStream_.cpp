
#include <zlib.h>

#include "GZipInputStream.hpp"

namespace NBT {

using std::string;

GZipInputStream::GZipInputStream(const string &fileName)
:closed(false) {
    file = gzopen(fileName.c_str(), "rb");
}

GZipInputStream::GZipInputStream(int fd)
:closed(false) {
    file = gzdopen(fd, "rb");
}

GZipInputStream::~GZipInputStream() {
    if (!closed) {
        close();
    }
}

void * GZipInputStream::read(void *bytes, size_t size) {
    if (!bytes) {
        bytes = new uint8_t[size];
    }
    gzread(file, bytes, size);
    return bytes;
}

void GZipInputStream::close() {
    closed = true;
    gzclose(file);
}

}
