#include "Span.hpp"

void	test(unsigned int a, unsigned int b)
{
	std::cout << "[a]" << std::endl;
	Span sp = Span(a);
	for (unsigned int i = 0; i < a; i ++)
		sp.addNumber(-42);
	sp.printSpan();
	std::cout << "short: "<< sp.shortestSpan() << std::endl; 
	std::cout << "long : " << sp.longestSpan() << std::endl;
	std::cout << "[b]" << std::endl;
	sp = Span(b);
	for (unsigned int i = 0; i < b; i++)
		sp.addNumber(42);
	sp.printSpan();
	std::cout << "short: " << sp.shortestSpan() << std::endl; 
	std::cout << "long : " << sp.longestSpan() << std::endl;
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
	std::cout << "=====================Add Function Test===================" << std::endl;
	try
	{
		sp = Span(10);
		sp.addNumberBunch(3);
		sp.addNumberBunch(4);
		sp.addNumberBunch(5);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	sp.printSpan();
	std::cout << "======================Large Span Test====================" << std::endl;
	sp = Span(10000);
	sp.addNumberBunch(10000);
	sp.printSortedSpan();
	std::cout << sp.shortestSpan() << std::endl; 
	std::cout << sp.longestSpan() << std::endl;
	sp = Span(10);
	sp.addNumberRandom(10);
	sp.printSpan();
	sp.printSortedSpan();
	std::cout << sp.shortestSpan() << std::endl; 
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "======================mem leak check=====================" << std::endl;
	system("leaks span");
	return 0; 
}
