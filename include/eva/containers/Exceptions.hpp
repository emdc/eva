#include <cstddef>
#include <exception>


namespace eva {
  class IndexException : public std::exception {
  public:
    IndexException(const std::size_t index, const std::size_t capacity)
      : std::exception(), _index(index), _capacity(capacity)
    {}

    const char* what () const noexcept override { return "Index is out of bounds"; }

    std::size_t index () const noexcept { return _index; }
    std::size_t capacity () const noexcept { return _capacity; }
  private:
    std::size_t _index;
    std::size_t _capacity;
  };
}