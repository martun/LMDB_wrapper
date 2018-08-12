#include "lmdb_wrappers.h"
#include "common/toolkit.h"
 
namespace LMDB {

// Throws a proper exception if rc contains an LMDB error.
void throw_if_error(int rc, std::string additional_info) {
  // TODO(martun): Write the exception handling once we create our own exceptions.
  if (rc != MDB_SUCCESS) {
    GDBE_THROW("LMDB failure: %s. [%s]", mdb_strerror(rc), additional_info);
  }
}

LMDBEnv::LMDBEnv(MDB_env* env) 
    :env_(env) {

}

LMDBEnv::~LMDBEnv() {
    mdb_env_close(env_);
}

MDB_env* LMDBEnv::get() {
    return env_;
}


LMDBCursor::LMDBCursor(MDB_cursor* cursor)
    : cursor_(cursor)
{

}

MDB_cursor* LMDBCursor::get() {
    return cursor_;
}

LMDBCursor::~LMDBCursor() {
    mdb_cursor_close(cursor_);
}

} // end of namespace LMDB.

