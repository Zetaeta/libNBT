
#include "GZipInputStream.hpp"

namespace NBT {

using std::string;

GZipInputStream::GZipInputStream(string fileName) {
    file = gzopen(fileName.c_str(), "rb");
}

void * GZipInputStream::read(void *bytes, size_t size) {
    if (!bytes) {
        bytes = new uint8_t[size];
    }
    gzread(file, bytes, size);
    return bytes;
}

void GZipInputStream::close() {
    gzclose(file);
}

}
