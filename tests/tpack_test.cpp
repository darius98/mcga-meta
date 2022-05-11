#include "mcga/meta/tpack.hpp"

#include <mcga/test.hpp>

using namespace mcga::meta;

TEST("tpack_contains") {
    static_assert(tpack_contains<tpack<int>, int>);
    static_assert(tpack_contains<tpack<int, long>, int>);
    static_assert(tpack_contains<tpack<int, long, long>, int>);
    static_assert(tpack_contains<tpack<long, int, long>, int>);
    static_assert(tpack_contains<tpack<long, long, int>, int>);
    static_assert(!tpack_contains<tpack<>, int>);
    static_assert(!tpack_contains<tpack<long>, int>);
    static_assert(!tpack_contains<tpack<long, char, long>, int>);
}

TEST("one_of_pack") {
    static_assert(one_of_pack<int, tpack<int>>);
    static_assert(one_of_pack<int, tpack<int, long>>);
    static_assert(one_of_pack<int, tpack<int, long, long>>);
    static_assert(one_of_pack<int, tpack<long, int, long>>);
    static_assert(one_of_pack<int, tpack<long, long, int>>);
    static_assert(!one_of_pack<int, tpack<>>);
    static_assert(!one_of_pack<int, tpack<long>>);
    static_assert(!one_of_pack<int, tpack<long, char, long>>);
}

TEST("one_of") {
  static_assert(one_of<int, int>);
  static_assert(one_of<int, int, long>);
  static_assert(one_of<int, int, long, long>);
  static_assert(one_of<int, long, int, long>);
  static_assert(one_of<int, long, long, int>);
  static_assert(!one_of<int>);
  static_assert(!one_of<int, long>);
  static_assert(!one_of<int, long, char, long>);
}

TEST("variant_for") {
    static_assert(std::is_same_v<variant_for<tpack<>>, std::variant<>>);
    static_assert(std::is_same_v<variant_for<tpack<int>>, std::variant<int>>);
    static_assert(
      std::is_same_v<variant_for<tpack<int, int>>, std::variant<int, int>>);
    static_assert(std::is_same_v<variant_for<tpack<int, std::string>>,
                                 std::variant<int, std::string>>);
}

TEST("tuple_for") {
    static_assert(std::is_same_v<tuple_for<tpack<>>, std::tuple<>>);
    static_assert(std::is_same_v<tuple_for<tpack<int>>, std::tuple<int>>);
    static_assert(
      std::is_same_v<tuple_for<tpack<int, int>>, std::tuple<int, int>>);
    static_assert(std::is_same_v<tuple_for<tpack<int, std::string>>,
                                 std::tuple<int, std::string>>);
}
