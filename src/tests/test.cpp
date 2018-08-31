#include <gtest/gtest.h>
#include <lmdb.h>
#include <random>
#include "lmdb_values.h"
#include "lmdb_dictionary.h"

TEST(LMDB_wrapper_tests, insert_find_test) {
    // creating dictionary with file path and map size (with bytes),
    LMDB::LMDBDictionary<LMDB::SampleKey, LMDB::SampleValue> dictionary("./testdb", 1024 * 1024);
    for(int i = 0; i < 64; ++i)
    {
        std::random_device rd;
        std::mt19937 rand(rd());
        // creating SampelKey object with i
        LMDB::SampleKey key(i);
        // generating random SampleValue object;
        LMDB::SampleValue value(rand(), rand());
        // creating transaction in this scope and
        // inserting key and value with that transaction,
        // out of scope (in transaction destructor) transaction commit is being called
        {
            auto txn1 = dictionary.new_txn();
            dictionary.insert(key, value, txn1);
        }
        // creating another transaction and finding element with key,
        auto txn2 = dictionary.new_txn();
        auto term1 = dictionary.find(key, txn2);
        // we are expecting initial value and found object to be equal
        EXPECT_TRUE(value == term1->second);
    }

}