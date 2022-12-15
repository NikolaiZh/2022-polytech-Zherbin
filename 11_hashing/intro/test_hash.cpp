#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "./hash.hpp"

#include <doctest.h>

TEST_CASE("whatever") {
  CHECK_EQ(cool_hash("test"), 1111111111);
  CHECK_EQ(cool_hash("tset"), 2222222222);
  CHECK_EQ(cool_hash("tste"), 3333333333);
}
