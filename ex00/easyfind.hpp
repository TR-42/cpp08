#pragma once

#include <cstddef>

template <typename T>
typename T::const_iterator easyfind(const T &container, int value);

#include "./easyfind.tpp"
