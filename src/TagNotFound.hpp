
#ifndef TAGNOTFOUND_HPP
#define TAGNOTFOUND_HPP

#include <stdexcept>

namespace NBT {

class TagNotFound : public std::runtime_error {
public:
    TagNotFound(const std::string &what);
};

}

#endif
