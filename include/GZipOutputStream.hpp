
#ifndef GZIPOUTPUTSTREAM_HPP
#define GZIPOUTPUTSTREAM_HPP

#include <string>

#include <zlib.h>

#include "OutputStream.hpp"

namespace NBT {

class GZipOutputStream : public OutputStream {
public:
    GZipOutputStream(std::string);
    void write(const void *bytes, int size);
    void close();
private:
    gzFile file;
};

}

#endif // GZIPOUTPUTSTREAM_HPP
