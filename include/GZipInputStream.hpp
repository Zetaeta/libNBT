
#ifndef GZIPINPUTSTREAM_HPP
#define GZIPINPUTSTREAM_HPP

#include <string>

#include <zlib.h>

#include "InputStream.hpp"

namespace NBT {

class GZipInputStream : public InputStream {
public:
    GZipInputStream(std::string);
    ~GZipInputStream();
    
    void * read(void *bytes, size_t size);
    void close();
private:
    gzFile file;
};

}

#endif // GZIPOUTPUTSTREAM_HPP
