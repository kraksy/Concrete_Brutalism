
#include <raylib.h>

class Shaders {
public:
  Shaders();
  Shaders(Shaders &&) = default;
  Shaders(const Shaders &) = default;
  Shaders &operator=(Shaders &&) = default;
  Shaders &operator=(const Shaders &) = default;
  ~Shaders();

  static void LoadShader(const char *path);
  static void UnloadShader(Shaders shad);

private:
};
