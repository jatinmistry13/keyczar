// Copyright 2009 Sebastien Martini (seb@dbzteam.org)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef KEYCZAR_KEYSET_FILE_READER_H_
#define KEYCZAR_KEYSET_FILE_READER_H_

#include <string>

#include "base/basictypes.h"
#include "base/file_path.h"
#include "base/values.h"

#include "keyczar/keyset_reader.h"

namespace keyczar {

// Class used for reading the content of a keyset (keys and metadata) from
// files.
class KeysetFileReader : public KeysetReader {
 public:
  // |dirname| is the string path of the keyset to read.
  explicit KeysetFileReader(const std::string& dirname);

  // |dirname| is the FilePath of the keyset to read.
  explicit KeysetFileReader(const FilePath& dirname);

  // Read the metadata. The caller takes ownership of the returned value.
  virtual Value* ReadMetadata() const;

  // Read the key |version|. The caller takes ownership of the returned value.
  virtual Value* ReadKey(int version) const;

  FilePath dirname() const { return dirname_; }

 private:
  const FilePath dirname_;
  const FilePath metadata_basename_;

  DISALLOW_COPY_AND_ASSIGN(KeysetFileReader);
};

}  // namespace keyczar

#endif  // KEYCZAR_KEYSET_FILE_READER_H_
