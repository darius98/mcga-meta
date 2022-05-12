#pragma once

#include <type_traits>

namespace mcga::meta {

template<class T, class U>
concept cvref_same_as = std::is_same_v < std::remove_cvref_t<T>,
std::remove_cvref_t < U >> ;

}  // namespace mcga::meta
