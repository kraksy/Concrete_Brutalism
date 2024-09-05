
#include "ModelLoad.h"

#include <cstddef>
#include <raylib.h>
#include <stdexcept>

static Model load(const char *path) {
  if (FileExists(path))
    return 0; // return nothing
  Model mdl = LoadModel(path);
  if (mdl.meshes = 0) {
    throw std::invalid_argument("mesh if invalid");
  } else {
    return mdl;
  }
  return 0; // need to return nothing
}
