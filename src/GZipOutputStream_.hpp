
#ifndef GZIPOUTPUTSTREAM_HPP
#define GZIPOUTPUTSTREAM_HPP

#include <string>

#include "OutputStream.hpp"

#ifndef ZLIB_H
typedef struct gzFile_s *gzFile;
#endif

namespace NBT {

class GZipOutputStream : public OutputStream {
public:
    GZipOutputStream(const std::string &);
    GZipOutputStream(int fd);
    ~GZipOutputStream();

    void write(const void *bytes, int size);
    void close();
private:
    gzFile file;
    bool closed;
};

}

#endif // GZIPOUTPUTSTREAM_HPP
