#include "Span.hpp"

Span::Span()
{
	_sizeMax = 0;
}

Span::Span(unsigned int N)
{
	_sizeMax = N;
}

Span::Span(const Span& copy)
{
	_span = copy.getSpan();
	_sizeMax = copy.getMaxSize();
}

Span&	Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		_span = copy.getSpan();
		_sizeMax = copy.getMaxSize();
	}
	return (*this);
}

Span::~Span()
{
}

const v& Span::getSpan(void) const
{
	return (_span);
}

unsigned int	Span::getMaxSize(void) const
{
	return (_sizeMax);
}

unsigned int	Span::getSize(void) const
{
	return (_span.size());
}

void	Span::addNumber(int n)
{
	if (_span.size() == _sizeMax)
		throw std::runtime_error("Cannot Add Exception :It's Already Full");
	_span.push_back(n);
}

int	randomNumber(void)
{
	return (std::rand());
}

void	Span::addNumberBunch(unsigned int size)
{
	if (_span.size() + size > _sizeMax)
		throw std::runtime_error("Cannot Add Exception: Size after add Exceeds Max Span Size");
	static int	srandFlag;
	if (srandFlag == 0)
	{
		std::srand(std::time(NULL));
		srandFlag = 1;
	}
	std::generate(_span.begin(), _span.end(), randomNumber);
}

unsigned int	Span::shortestSpan(void)
{
	if (_span.size() <= 1)
		throw std::runtime_error("Cannot Get Span Exception: Too few Argument");
	mSet	distances;
	v::iterator	it = _span.begin();
	while (it != _span.end())
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
	std::sort(_span.begin(), _span.end());
	v::iterator it = _span.begin();
	std::advance(it, (_span.size() - 1));
	return (std::abs(*it - *_span.begin()));
}
