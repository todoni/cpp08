#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <iterator>

typedef std::multiset<int> mSet;
typedef std::vector<int> v;

class	Span
{
	private:
		std::vector<int>	_span;
		unsigned int		_sizeMax;
	
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span& copy);
		Span& operator=(const Span& copy);

		void			addNumber(int n);
		void			addNumberBunch(unsigned int n);
		void			addNumber(void);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		unsigned int	getMaxSize(void) const;
		unsigned int	getSize(void) const;
		const v&		getSpan(void) const;
	
	
};


#endif
