
#include "raylib.h"

class ModelLoad {
public:
  ModelLoad() = default;
  ModelLoad(ModelLoad &&) = default;
  ModelLoad(const ModelLoad &) = default;
  ModelLoad &operator=(ModelLoad &&) = default;
  ModelLoad &operator=(const ModelLoad &) = default;
  ~ModelLoad() = default;

  static bool check(); // check if everything works
  static Model load(const char path);

private:
};
