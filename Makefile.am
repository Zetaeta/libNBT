#SUBDIRS = src

ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libNBT.la

libNBT_la_includedir = $(includedir)/nbt

libNBT_la_CXXFLAGS = -g -fPIC -std=c++11 -Wall
#libNBT_la_LDFLAGS = 

libNBT_la_LDFLAGS =  #-lz -Wl,-Bstatic,-lendian,-Bdynamic 
libNBT_la_LIBADD = -lendian -lIOStream -lz

libNBT_la_SOURCES = src/InvalidTagId.cpp src/TagNotFound.cpp \
     src/NBT.cpp src/Tag.cpp src/TagByte.cpp src/TagShort.cpp src/TagInt.cpp \
     src/TagLong.cpp src/TagFloat.cpp src/TagDouble.cpp src/TagByteArray.cpp \
     src/TagString.cpp src/TagList.cpp src/TagCompound.cpp src/TagIntArray.cpp

libNBT_la_include_HEADERS = src/Streams.hpp \
    src/NBT.hpp src/NBTLib.hpp src/InvalidTagId.hpp src/TagNotFound.hpp \
    src/Tags.hpp src/Tag.hpp src/TagByte.hpp src/TagShort.hpp \
    src/TagInt.hpp src/TagLong.hpp src/TagFloat.hpp src/TagDouble.hpp \
    src/TagByteArray.hpp src/TagString.hpp src/TagList.hpp \
    src/TagCompound.hpp src/TagIntArray.hpp src/TagEnd.hpp
