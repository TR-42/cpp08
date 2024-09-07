#include "./Span.hpp"

Span::Span(
) : _capacity(0),
		_vec()
{
}

Span::Span(
	std::size_t capacity
) : _capacity(capacity),
		_vec()
{
	this->_vec.reserve(capacity);
}

Span::~Span(
)
{
}

Span::Span(
	const Span &src
) : _capacity(src._capacity),
		_vec(src._vec)
{
}

Span &Span::operator=(
	const Span &src
)
{
	if (this == &src) {
		return *this;
	}

	this->_capacity = src._capacity;
	this->_vec = src._vec;

	return *this;
}

void Span::addNumber(
	int number
)
{
	if (this->_vec.size() == this->_capacity) {
		throw std::runtime_error("Span is full");
	}

	for (
		std::vector<int>::const_iterator it = this->_vec.begin();
		it != this->_vec.end();
		++it
	) {
		if (number < *it) {
			this->_vec.insert(it, number);
			return;
		}
	}
	this->_vec.push_back(number);
}

int Span::shortestSpan() const
{
	if (this->_vec.size() <= 1) {
		throw std::runtime_error("Span is empty or has only one element");
	}

	int shortest = this->_vec[1] - this->_vec[0];
	for (std::size_t i = 1; i < this->_vec.size() - 1; ++i) {
		int diff = this->_vec[i + 1] - this->_vec[i];
		if (diff == 0) {
			return 0;
		} else if (diff < shortest) {
			shortest = diff;
		}
	}

	return shortest;
}

int Span::longestSpan() const
{
	if (this->_vec.size() <= 1) {
		throw std::runtime_error("Span is empty or has only one element");
	}

	return this->_vec.back() - this->_vec.front();
}
