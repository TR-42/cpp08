#pragma once

#include <algorithm>
#include <stdexcept>

#include "./easyfind.hpp"

template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	return std::find(container.begin(), container.end(), value);
}
