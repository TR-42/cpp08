#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "./Span.hpp"

#define RAND_SEED 0
#define MANY_COUNT 100000

static void test_5elem()
{
	Span sp(5);

	try {
		std::cout << "initial shortestSpan: " << sp.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "initial longestSpan: " << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		sp.addNumber(6);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		std::exit(1);
	}
	try {
		std::cout << "{6} shortestSpan: " << sp.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "{6} longestSpan: " << e.what() << std::endl;
	}

	try {
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		std::exit(1);
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
		std::cout << "# add 18" << std::endl;
		sp.addNumber(18);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

typedef std::vector<int>::const_iterator vec_cit;
static void test_many()
{
	// 常に同じ値を返すようにする
	std::srand(RAND_SEED);

	Span sp = Span(MANY_COUNT);

	{
		std::vector<int> vec;
		vec.reserve(MANY_COUNT);
		for (std::size_t i = 0; i < MANY_COUNT; ++i) {
			int num = std::rand();
#ifdef DEBUG
			std::cout << "vec[" << i << "]: " << num << std::endl;
#endif
			vec.push_back(num);
		}
		sp.addRange(vec.begin(), vec.end());
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
		std::cout << "# add 18" << std::endl;
		sp.addNumber(18);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	std::cout << "=== test_5elem ===" << std::endl;
	test_5elem();

	std::cout << "=== test_many ===" << std::endl;
	test_many();

	return 0;
}
