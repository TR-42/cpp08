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

	typename T::const_iterator iter = easyfind(v, 2);

	std::cout << "Iter2: " << &(*iter) << " / " << *iter << std::endl;

	iter = easyfind(v, 4);
	std::cout << "Iter4: " << &(*iter) << " / " << std::boolalpha << (iter == v.end()) << std::endl;
}

typedef std::vector<int> int_vector;
typedef std::list<int> int_list;
int main(void)
{
	test<int_vector>();
	test<int_list>();

	return 0;
}
