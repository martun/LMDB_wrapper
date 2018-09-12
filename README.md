## LMDB C++ Wrapper
C++ style LMDB database wrapper, which makes usage of LMDB very similiar to usage of std::map, I.E. you have iterators and so on. Makes it very easy for you to change and code that uses std::map to use LMDB instead. 

## Building
Build project:

    cd /path/to/project
    mkdir build
    cd build
    cmake ..
    make -j4

Debug Build: 

    cd /path/to/project
    mkdir build_debug
    cd build_debug
    cmake -DCMAKE_BUILD_TYPE=Debug ..
    make -j4

## Testing
We use [Google Test](https://github.com/google/googletest) for unit testing.

To run the tests:
    make test

## Contact e-mail
martun.karapetyan@gmail.com

## Articles
Link to the LMDB itself: 
[LMDB database, good for a memory cache.](https://github.com/LMDB/lmdb)
