enable_testing()

add_test(
        NAME LMDB_wrapper_test
        COMMAND insert_find_test
)

add_executable(LMDB_wrapper_test
        main.cpp
        test.cpp
        )

target_link_libraries(LMDB_wrapper_test
        lmdb
        LMDB_wrapper
        gtest
        )