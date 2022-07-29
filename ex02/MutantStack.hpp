#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <list>
# include <deque>
# include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack()
			:std::stack<T>() {};
		MutantStack(MutantStack const &copy)
			:std::stack<T>(copy) {};
		virtual ~MutantStack() {};

		MutantStack<T> &operator=(MutantStack<T> const &copy) { 
			this->c = copy.c;
			return (*this);};

		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator	begin(void) { return (this->c.begin()); };
		iterator	end(void) { return (this->c.end()); };

		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin() { return (this->c.rbegin()); };
		reverse_iterator	rend() { return (this->c.rend()); };
};

#endif
