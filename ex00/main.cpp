#include <iostream>
#include <list>
#include <vector>

#include "./easyfind.hpp"

template <typename T>
static void test()
{
	T v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::size_t index = easyfind(v, 2);

	std::cout << "Index: " << index << std::endl;

	try {
		index = easyfind(v, 4);
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

typedef std::vector<int> int_vector;
typedef std::list<int> int_list;
int main(void)
{
	test<int_vector>();
	test<int_list>();

	return 0;
}
