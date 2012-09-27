
#ifndef INVALIDTAGID_HPP
#define INVALIDTAGID_HPP

#include <stdexcept>
#include <string>

namespace NBT {

class InvalidTagId : public std::invalid_argument {
public:
    InvalidTagId();
    InvalidTagId(const std::string &message);
    ~InvalidTagId() throw();
private:
    std::string message;
};

}

#endif
