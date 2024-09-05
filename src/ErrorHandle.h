
class ErrorHandle {
public:
  ErrorHandle();
  ErrorHandle(ErrorHandle &&) = default;
  ErrorHandle(const ErrorHandle &) = default;
  ErrorHandle &operator=(ErrorHandle &&) = default;
  ErrorHandle &operator=(const ErrorHandle &) = default;
  ~ErrorHandle();

  static void basicHandle();

private:
};
