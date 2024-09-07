#pragma once

#include <stdexcept>

#include "./easyfind.hpp"

template <typename T>
std::size_t easyfind(const T &container, int value)
{
	size_t index = 0;
	for (
		typename T::const_iterator it = container.begin();
		it != container.end();
		++it
	) {
		if (*it == value)
			return index;
		++index;
	}

	throw std::runtime_error("Value not found");
}
