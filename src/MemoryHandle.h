
class MemoryHandle {
public:
  MemoryHandle();
  MemoryHandle(MemoryHandle &&) = default;
  MemoryHandle(const MemoryHandle &) = default;
  MemoryHandle &operator=(MemoryHandle &&) = default;
  MemoryHandle &operator=(const MemoryHandle &) = default;
  ~MemoryHandle();

  static void clear();

private:
};
