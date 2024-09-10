class Render {
public:
  Render() = default;
  Render(Render &&) = default;
  Render(const Render &) = default;
  Render &operator=(Render &&) = default;
  Render &operator=(const Render &) = default;
  ~Render() = default;

  static bool init();
  static void startRendering();
  static void del();

private:
  static bool debugging();
};
