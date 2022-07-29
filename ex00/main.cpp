#include "easyfind.hpp"

int	main()
{
	std::vector<int> myVec;
	std::deque<int> myDeque;
	std::list<int>	myList;

	for (int i = 0; i < 9; i++)
	{	
		myVec.push_back(1);
		myDeque.push_back(1);
		myList.push_back(1);
	}
	myVec.push_back(0);
	myDeque.push_back(0);
	myList.push_back(0);
	std::cout << "=====Findable Test=====" << std::endl;
	test(myVec, easyfind, 0);
	test(myDeque, easyfind, 0);
	test(myList, easyfind, 0);
	std::cout << "====Not Found Test=====" << std::endl;
	test(myVec, easyfind, 3);
	test(myDeque, easyfind, 3);
	test(myList, easyfind, 3);
}
