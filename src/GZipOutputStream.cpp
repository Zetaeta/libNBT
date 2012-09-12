
#include "GZipOutputStream.hpp"

namespace NBT {

using std::string;

GZipOutputStream::GZipOutputStream(string fileName) {
    file = gzopen(fileName.c_str(), "wb");
}

void GZipOutputStream::write(const void *bytes, int size) {
    gzwrite(file, bytes, size);
}

void GZipOutputStream::close() {
    gzclose(file);
}

}
