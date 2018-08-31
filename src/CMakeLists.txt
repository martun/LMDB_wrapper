cmake_minimum_required(VERSION 2.8)

link_libraries(boost_filesystem
        boost_system)
add_library(LMDB_wrapper
        lmdb_dictionary.h
        lmdb_dictionary.hpp
        lmdb_values.h
        lmdb_values.cc
        lmdb_wrappers.h
        lmdb_wrappers.cc)





add_subdirectory(tests)