#include "Span.hpp"

Span::Span()
	:_span(0, 0)
{
	_span.reserve(0);
}

Span::Span(unsigned int N)
	:_span(0, 0)
{
	_span.reserve(N);
}

Span::Span(const Span& copy)
{
	_span.reserve(copy.getSpan().capacity());
	std::copy(copy.getSpan().begin(), copy.getSpan().end(), _span.begin());
}

Span&	Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		_span.reserve(copy.getSpan().capacity());
		_span.resize(copy.getSpan().size());
		std::copy(copy.getSpan().begin(), copy.getSpan().end(), _span.begin());
		//_span = copy.getSpan();
	}
	return (*this);
}

Span::~Span()
{
}

const std::vector<int>& Span::getSpan(void) const
{
	return (_span);
}

void	Span::printSpan(void)
{
	std::cout << "[span]" << std::endl;
	for (std::vector<int>::iterator it = _span.begin(); it != _span.end(); it++)
		std::cout << *it << " ";
	std::cout << " size: " << _span.size() << std::endl;
}

void	Span::printSortedSpan(void)
{
	std::cout << "[sorted]" << std::endl;
	std::vector<int> copy = getSpan();
	std::sort(copy.begin(), copy.end());
	for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	Span::addNumber(int n)
{
	if (_span.size() == _span.capacity())
		throw std::runtime_error("Cannot Add Exception :It's Already Full");
	_span.push_back(n);
}

int	randomNumber(void)
{
	return (std::rand() % 100);
}

int	ascendingNumber(void)
{
	static int i;
	return (++i);
}

void	Span::addNumberBunch(unsigned int size)
{
	if (_span.size() + size > _span.capacity())
		throw std::runtime_error("Cannot Add Exception: Size after add Exceeds Max Span Size");
	std::vector<int> big(size);
	std::generate(big.begin(), big.end(), ascendingNumber);
	std::copy(big.begin(), big.end(), std::back_inserter(_span));
}

void	Span::addNumberRandom(unsigned int size)
{
	if (_span.size() + size > _span.capacity())
		throw std::runtime_error("Cannot Add Exception: Size after add Exceeds Max Span Size");
	static int	srandFlag;
	if (srandFlag == 0)
	{
		std::srand(std::time(NULL));
		srandFlag = 1;
	}
	std::vector<int> big(size);
	std::generate(big.begin(), big.end(), randomNumber);
	std::copy(big.begin(), big.end(), std::back_inserter(_span));
}

unsigned int	Span::shortestSpan(void)
{
	if (_span.size() <= 1)
		throw std::runtime_error("Cannot Get Span Exception: Too few Argument");
	mSet	distances;
	std::vector<int> copy = getSpan();
	std::sort(copy.begin(), copy.end());
	v::iterator	it = copy.begin();
	while (it != copy.end())
	{
		int	current = *it;
		std::advance(it, 1);
		int next = *it;
		if (it != _span.end())
			distances.insert(std::abs(next - current));
	}
	return (*distances.begin());
}

unsigned int	Span::longestSpan(void)
{
	if (_span.size() <= 1)
		throw std::runtime_error("Cannot Get Span Exception: Too few Argument");
	std::vector<int> copy = getSpan();
	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator it = copy.begin();
	std::advance(it, (copy.size() - 1));
	return (std::abs(*it - *copy.begin()));
}
