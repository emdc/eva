#include <catch2/catch.hpp>

#include <eva/containers/Array.hpp>


TEST_CASE("[containers/Array/Array] Check access to elements - 1", "[multi-file]") {
  eva::Array<int, 2> arr;

  arr[0] = 1;
  arr[1] = 2;

  REQUIRE(arr[0] == 1);
  REQUIRE(arr[1] == 2);
}

TEST_CASE("[containers/Array/Array] Check access to elements - 2", "[multi-file]") {
  eva::Array<int, 2> arr;

  arr[0] = 1;
  arr[1] = 2;

  REQUIRE_THROWS(arr[2] = 1);
}

TEST_CASE("[containers/Array/Array] Check access to elements - 3", "[multi-file]") {
  eva::Array<int, 2> arr;

  REQUIRE(arr.capacity() == 2);
}

TEST_CASE("[containers/Array/DynamicArray] Check dynamic array initials - 1", "[multi-file]") {
  eva::DynamicArray<int> a;

  REQUIRE(a.size() == 0);
  REQUIRE(a.capacity() == 0);
}

TEST_CASE("[containers/Array/DynamicArray] Check dynamic array initials - 2", "[multi-file]") {
  eva::DynamicArray<int> a(5);

  REQUIRE(a.size() == 5);
  REQUIRE(a.capacity() == 5);
}

TEST_CASE("[containers/Array/DynamicArray] Set elements - 1", "[multi-file]") {
  eva::DynamicArray<int> a;

  REQUIRE_THROWS(a[0] = 1);
  REQUIRE_THROWS(a[0]);
}

TEST_CASE("[containers/Array/DynamicArray] Set elements - 2", "[multi-file]") {
  eva::DynamicArray<int> a(5);

  a[0] = 1;

  REQUIRE(a[0] == 1);
}
