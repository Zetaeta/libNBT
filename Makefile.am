#SUBDIRS = src

ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libNBT.la

libNBT_la_includedir = $(includedir)/nbt

libNBT_la_CXXFLAGS = -std=c++11 -I include/

libNBT_la_SOURCES = src/GZipInputStream.cpp src/GZipOutputStream.cpp \
     src/NBT.cpp src/TagByte.cpp src/TagShort.cpp src/TagInt.cpp \
     src/TagLong.cpp src/TagFloat.cpp src/TagDouble.cpp src/TagByteArray.cpp \
     src/TagString.cpp src/TagList.cpp src/TagCompound.cpp src/TagIntArray.cpp

libNBT_la_include_HEADERS = include/GZipInputStream.hpp include/GZipOutputStream.hpp \
    include/InputStream.hpp include/OutputStream.hpp include/Streams.hpp \
    include/NBT.hpp include/NBTLib.hpp include/InvalidTagId.hpp \
    include/Tags.hpp include/Tag.hpp include/TagByte.hpp include/TagShort.hpp \
    include/TagInt.hpp include/TagLong.hpp include/TagFloat.hpp include/TagDouble.hpp \
    include/TagByteArray.hpp include/TagString.hpp include/TagList.hpp \
    include/TagCompound.hpp include/TagIntArray.hpp include/TagEnd.hpp
