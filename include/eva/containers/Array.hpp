#include <cstddef>

#include <iostream>

#include <eva/containers/Exceptions.hpp>


namespace eva {
  template<typename T, std::size_t Capacity>
  class Array {
  public:
    constexpr std::size_t   capacity () const noexcept { return Capacity; }
    constexpr std::size_t   size () const noexcept { return Capacity; }

    inline    T&            operator [] (const std::size_t index);
    constexpr T             operator [] (const std::size_t index) const;

  private:
    T         _data[Capacity];
  };

  template<typename T>
  class DynamicArray {
  public:
              DynamicArray();
    explicit  DynamicArray(const std::size_t capacity);
              ~DynamicArray();

              std::size_t   capacity () const noexcept { return _capacity; }
              std::size_t   size () const noexcept { return _capacity; }

    inline    T&            operator [] (const std::size_t index);
    inline    T             operator [] (const std::size_t index) const;

  private:
    std::size_t   _capacity;
    T*            _data;
  };

  // ==========================================================================
  // Array<T> Implementation

  template<typename T, std::size_t Capacity>
  T& Array<T, Capacity>::operator[] (const std::size_t index) {
    if (Capacity == 0 || index >= Capacity) {
      throw IndexException(index, Capacity);
    }

    return _data[index];
  }

  template<typename T, std::size_t Capacity>
  constexpr T Array<T, Capacity>::operator[] (const std::size_t index) const {
    if (Capacity == 0 || index >= Capacity) {
      throw IndexException(index, Capacity);
    }

    return _data[index];
  }

  // --------------------------------------------------------------------------
  // DynamicArray<T> implementation

  template<typename T>
  DynamicArray<T>::DynamicArray()
    : _capacity(0), _data(nullptr)
  {}

  template<typename T>
  DynamicArray<T>::DynamicArray(const std::size_t capacity)
    : _capacity(capacity)
  {
    _data = new T[capacity];
  }

  template<typename T>
  DynamicArray<T>::~DynamicArray() {
    delete _data;
  }

  template<typename T>
  T& DynamicArray<T>::operator [] (const std::size_t index) {
    if (_capacity == 0 || index >= _capacity) {
      throw IndexException(index, _capacity);
    }

    return _data[index];
  }

  template<typename T>
  T DynamicArray<T>::operator [] (const std::size_t index) const {
    if (_capacity == 0 || index >= _capacity) {
      throw IndexException(index, _capacity);
    }

    return _data[index];
  }
}
