
#ifndef GZIPINPUTSTREAM_HPP
#define GZIPINPUTSTREAM_HPP

#include <string>

#include "InputStream.hpp"

#ifndef ZLIB_H
typedef struct gzFile_s *gzFile;
#endif

namespace NBT {

class GZipInputStream : public InputStream {
public:
    GZipInputStream(const std::string &);
    GZipInputStream(int fd);
    ~GZipInputStream();
    
    void * read(void *bytes, size_t size);
    void close();
private:
    gzFile file;
    bool closed;
};

}

#endif // GZIPOUTPUTSTREAM_HPP
