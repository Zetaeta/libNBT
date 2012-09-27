
#include "Tag.hpp"

namespace NBT {

using std::string;

Tag::Tag()
    :name("") {}

Tag::Tag(string name)
    :name(name) {}

string Tag::getName() const {
    return name;
}

void Tag::setName(string name) {
    this->name = name;
}

}

