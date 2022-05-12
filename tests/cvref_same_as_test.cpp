#include "mcga/meta.hpp"

#include <mcga/test.hpp>

using namespace mcga::meta;

TEST("cvref_same_as") {
    static_assert(cvref_same_as<int, int>);
    static_assert(cvref_same_as<int, int&>);
    static_assert(cvref_same_as<int, int&&>);
    static_assert(cvref_same_as<int, const int>);
    static_assert(cvref_same_as<int, const int&>);
    static_assert(cvref_same_as<int, const int&&>);
    static_assert(cvref_same_as<int, volatile int>);
    static_assert(cvref_same_as<int, volatile int&>);
    static_assert(cvref_same_as<int, volatile int&&>);
    static_assert(cvref_same_as<int, const volatile int>);
    static_assert(cvref_same_as<int, const volatile int&>);
    static_assert(cvref_same_as<int, const volatile int&&>);

    static_assert(cvref_same_as<const int&, int>);
    static_assert(cvref_same_as<const int&, int&>);
    static_assert(cvref_same_as<const int&, int&&>);
    static_assert(cvref_same_as<const int&, const int>);
    static_assert(cvref_same_as<const int&, const int&>);
    static_assert(cvref_same_as<const int&, const int&&>);
    static_assert(cvref_same_as<const int&, volatile int>);
    static_assert(cvref_same_as<const int&, volatile int&>);
    static_assert(cvref_same_as<const int&, volatile int&&>);
    static_assert(cvref_same_as<const int&, const volatile int>);
    static_assert(cvref_same_as<const int&, const volatile int&>);
    static_assert(cvref_same_as<const int&, const volatile int&&>);

    static_assert(!cvref_same_as<int, long>);
    static_assert(!cvref_same_as<int&, long>);
    static_assert(!cvref_same_as<const int, long>);
    static_assert(!cvref_same_as<const int&, long>);
    static_assert(!cvref_same_as<int, const long>);
    static_assert(!cvref_same_as<int, volatile long>);
    static_assert(!cvref_same_as<int, const long&>);
    static_assert(!cvref_same_as<int, const long&&>);
}
