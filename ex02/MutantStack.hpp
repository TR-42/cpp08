#pragma once

#include <algorithm>
#include <cstddef>
#include <deque>
#include <list>
#include <stack>
#include <stdexcept>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
 public:
	typedef typename MutantStack::container_type::iterator iterator;
	typedef typename MutantStack::container_type::const_iterator const_iterator;
	typedef typename MutantStack::container_type::reverse_iterator reverse_iterator;
	typedef typename MutantStack::container_type::const_reverse_iterator const_reverse_iterator;

	MutantStack();
	virtual ~MutantStack();
	MutantStack(const MutantStack<T, Container> &src);
	MutantStack &operator=(const MutantStack<T, Container> &src);

	MutantStack::iterator begin();
	MutantStack::iterator end();

	MutantStack::const_iterator begin() const;
	MutantStack::const_iterator end() const;

	MutantStack::reverse_iterator rbegin();
	MutantStack::reverse_iterator rend();

	MutantStack::const_reverse_iterator rbegin() const;
	MutantStack::const_reverse_iterator rend() const;
};

#include "./MutantStack.tpp"
