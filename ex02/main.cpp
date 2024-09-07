#include <iostream>

#include "./MutantStack.hpp"

#define STACK_RAND_PUSH 16

static void subject_test()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

template <typename T>
static void printIterable(const T &iterable)
{
	size_t i = 0;
	for (
		typename T::const_iterator it = iterable.begin();
		it != iterable.end();
		++it
	) {
		std::cout << "arr[" << i++ << "]: " << *it << std::endl;
	}
	if (i == 0) {
		std::cout << "empty" << std::endl;
	}
}

template <typename T>
static void x2Iterable(T &iterable)
{
	for (
		typename T::iterator it = iterable.begin();
		it != iterable.end();
		++it
	) {
		*it *= 2;
	}
}

static void my_test()
{
	MutantStack<int> mstack;
	std::cout << "# Empty Stack" << std::endl;
	printIterable(mstack);
	std::cout << "size: " << mstack.size() << std::endl;

	std::cout << "# push 5" << std::endl;
	mstack.push(5);
	printIterable(mstack);
	std::cout << "size: " << mstack.size() << std::endl;

	// 常に固定値
	std::srand(0);
	for (int i = 0; i < STACK_RAND_PUSH; ++i) {
		mstack.push(std::rand());
	}

	std::cout << "# pushed" << STACK_RAND_PUSH << " random values" << std::endl;
	printIterable(mstack);
	std::cout << "size: " << mstack.size() << std::endl;

	std::cout << "# x2" << std::endl;
	x2Iterable(mstack);
	printIterable(mstack);
	std::cout << "size: " << mstack.size() << std::endl;
}

int main()
{
	std::cout << "=== subject_test ===" << std::endl;
	subject_test();

	std::cout << "=== my_test ===" << std::endl;
	my_test();
	return 0;
}
