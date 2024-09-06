
#include "ModelLoad.h"

#include <raylib.h>
#include <stdexcept>

static bool check(const char dir) {
  if (DirectoryExists("../resources")) {
    return true;
  }
  // maybe check every file?
  exit(-1);
}

// ik im redifining the functions but , with this I can atleast catch the errors

static Model loadMesh(const char *path) {
  Model mdl = LoadModel(path);
  if (mdl.meshCount == 0 || mdl.materialCount == 0) {
    throw std::invalid_argument("model did not load");
    UnloadModel(mdl);
  } else {
    return mdl;
  }
  exit(-1);
}

static Texture2D loadTexture(const char *path) {
  Texture2D tex = loadTexture(path);
  if (tex.height == 0 || tex.width == 0) {
    throw std::invalid_argument("texture did not load");
    UnloadTexture(tex);
  } else {
    return tex;
  }
  exit(-1);
}

static bool finilizeModel(Model mod, Texture2D tex) {
  if (mod.meshCount == 0 || mod.materialCount == 0) {
    if (tex.height == 0 || tex.width == 0) {
      throw std::invalid_argument("both texture and model did not load");
      exit(-1);
    }
    throw std::invalid_argument("the model did not load");
  } else {
    mod.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = tex;
  }
  exit(-1);
}
