
#include "raylib.h"

class ModelLoad {
public:
  ModelLoad() = default;
  ModelLoad(ModelLoad &&) = default;
  ModelLoad(const ModelLoad &) = default;
  ModelLoad &operator=(ModelLoad &&) = default;
  ModelLoad &operator=(const ModelLoad &) = default;
  ~ModelLoad() = default;

  static bool check(const char dir); // check if everything works
  static Model loadMesh(const char path);
  static Texture2D loadTexture(const char path);

  static bool finilizeModel(Model mod, Texture2D tex);
  static void delModel(Model mod);

private:
};
