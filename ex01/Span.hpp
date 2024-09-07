#pragma once

#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <vector>

class Span
{
 private:
	std::size_t _capacity;
	std::vector<int> _vec;

 public:
	Span();
	Span(std::size_t capacity);
	virtual ~Span();
	Span(const Span &src);
	Span &operator=(const Span &src);

	void addNumber(int number);

	int shortestSpan() const;
	int longestSpan() const;

	template <class T>
	void addRange(
		T begin,
		T end
	)
	{
		while (begin != end) {
			if (this->_vec.size() == this->_capacity) {
				throw std::runtime_error("Span is full");
			}
			this->_vec.push_back(*begin);
			++begin;
		}
		std::sort(this->_vec.begin(), this->_vec.end());
	}
};
