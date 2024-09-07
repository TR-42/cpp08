#pragma once

#include "./MutantStack.hpp"

#define impl(type, name) \
	template <typename T, class Container> \
	typename MutantStack<T, Container>::type MutantStack<T, Container>::name() \
	{ \
		return this->c.name(); \
	} \
	template <typename T, class Container> \
	typename MutantStack<T, Container>::const_##type MutantStack<T, Container>::name() const \
	{ \
		return this->c.name(); \
	}

impl(iterator, begin);
impl(iterator, end);

impl(reverse_iterator, rbegin);
impl(reverse_iterator, rend);

#undef impl

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(
)
{
}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack(
)
{
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(
	const MutantStack<T, Container> &src
) : std::stack<T, Container>(src)
{
}

template <typename T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(
	const MutantStack<T, Container> &src
)
{
	std::stack<T, Container>::operator=(src);

	return *this;
}
