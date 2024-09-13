
#include <raylib.h>

class Shaders {
public:
  Shaders();
  Shaders(Shaders &&) = default;
  Shaders(const Shaders &) = default;
  Shaders &operator=(Shaders &&) = default;
  Shaders &operator=(const Shaders &) = default;
  ~Shaders();

  Shader ShaderList[1];

  static void ConnectShader(const char *path);
  static void DisconnectShader(Shader shad);

private:
  static int GetShadeListPos();
  static void ClearShaderList();
};
