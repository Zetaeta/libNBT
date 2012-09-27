
#include <zlib.h>

#include "GZipOutputStream.hpp"

namespace NBT {

using std::string;

GZipOutputStream::GZipOutputStream(const string &fileName)
:closed(false) {
    file = gzopen(fileName.c_str(), "wb");
}

GZipOutputStream::GZipOutputStream(int fd)
:closed(false) {
    file = gzdopen(fd, "rb");
}

GZipOutputStream::~GZipOutputStream() {
    if (!closed) {
        close();
    }
}

void GZipOutputStream::write(const void *bytes, int size) {
    gzwrite(file, bytes, size);
}

void GZipOutputStream::close() {
    closed = true;
    gzclose(file);
}

}
