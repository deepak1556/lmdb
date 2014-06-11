/* Copyright (c) 2013 Rod Vagg
 * MIT +no-false-attribs License <https://github.com/rvagg/lmdb/blob/master/LICENSE>
 */

#include "nlmdb.h"
#include "database.h"
#include "batch.h"
#include "iterator.h"

namespace nlmdb {

void Init (v8::Handle<v8::Object> target) {
  Database::Init();
  WriteBatch::Init();
  Iterator::Init();

  v8::Local<v8::Function> nlmdb =
      NanNew<v8::FunctionTemplate>(NLMDB)->GetFunction();

  target->Set(NanNew<v8::String>("nlmdb"), nlmdb);
}

NODE_MODULE(nlmdb, Init)

} // namespace nlmdb
