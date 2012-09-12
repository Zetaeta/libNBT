
#include "InvalidTagId.hpp"

namespace NBT {

using std::invalid_argument;

InvalidTagId::InvalidTagId()
:invalid_argument("") {}

InvalidTagId::InvalidTagId(const std::string &message)
:invalid_argument(message) {
}

InvalidTagId::~InvalidTagId() throw() {}

}
