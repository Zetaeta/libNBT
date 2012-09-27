
#include "TagNotFound.hpp"

namespace NBT {

TagNotFound::TagNotFound(const std::string &what)
:runtime_error(what) {
}

}

