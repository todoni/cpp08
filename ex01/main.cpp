#include "Span.hpp"

void	test(unsigned int a, unsigned int b)
{
	std::cout << "[a]" << std::endl;
	Span sp = Span(a);
	for (unsigned int i = 0; i < a; i ++)
		sp.addNumber(-42);
	std::vector<int> copy = sp.getSpan();
	for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
		std::cout << *it  << " ";
	std::cout << std::endl;
	
	std::cout << "short: "<< sp.shortestSpan() << std::endl; 
	std::cout << "long : " << sp.longestSpan() << std::endl;
	std::cout << "size : " << sp.getSize() << std::endl;

	
	std::cout << "[b]" << std::endl;
	sp = Span(b);
	for (unsigned int i = 0; i < b; i++)
		sp.addNumber(42);
	std::vector<int> copy2 = sp.getSpan();
	for (std::vector<int>::iterator it = copy2.begin(); it != copy2.end(); it++)
		std::cout << *it  << " ";
	std::cout << std::endl;
	std::cout << "short: " << sp.shortestSpan() << std::endl; 
	std::cout << "long : " << sp.longestSpan() << std::endl;
	std::cout << "size : " << sp.getSize() << std::endl;
}

int main() 
{
  	Span sp = Span(5);
	sp.addNumber(6); 
	sp.addNumber(3); 
	sp.addNumber(17); 
	sp.addNumber(9); 
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl; 
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "==============Different Size assignment test=============" << std::endl;
	test(10, 5);
	test(5, 10);
	std::cout << "=====================Add to full Span====================" << std::endl;
	try
	{
		sp.addNumber(128);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "=====================Invalid Span Test===================" << std::endl;
	sp = Span();
	try
	{
		std::cout << sp.shortestSpan() << std::endl; 
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "======================mem leak check=====================" << std::endl;
	system("leaks span");
	return 0; 
}
