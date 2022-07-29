#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <vector>
# include <list>
# include <deque>
# include <stdexcept>
# include <iostream>
//# include <stack>
//# include <queue> // container adapter
//# include <set> // associative container

template <typename T>
typename T::iterator	easyfind(T& container, int toFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw std::runtime_error("Number Not Found!");
	return (it);
}

template <typename T>
void	test(T& c, typename T::iterator (*fn)(T& c, int n), int n)
{
	try
	{
		typename T::iterator it = fn(c, n);
		std::cout << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
#endif
