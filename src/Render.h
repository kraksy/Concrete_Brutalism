class Render {
public:
  Render() = default;
  Render(Render &&) = default;
  Render(const Render &) = default;
  Render &operator=(Render &&) = default;
  Render &operator=(const Render &) = default;
  ~Render() = default;

  static void init();

private:
  static void LoadShader();
  static bool debugging;
};
