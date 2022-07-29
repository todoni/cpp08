#include "MutantStack.hpp"

int			main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Subject Main :" << std::endl;
	std::cout << "mstack.top() : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.pop() | mstack.size() : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(100);
	mstack.push(-99);
	mstack.push(10);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	--it;
	std::cout << "=======print mstack using iterator======" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	

	{
	std::cout << "===========list version===========" << std::endl;
	std::list<int> myList;
	myList.push_back(5);
	myList.push_back(17);

	std::cout << "Subject Main :" << std::endl;
	std::cout << "myList.top() : " << myList.front() << std::endl;
	myList.pop_front();
	std::cout << "myList.pop() | myList.size() : " << myList.size() << std::endl;

	myList.push_back(3);
	myList.push_back(5);
	myList.push_back(737);
	myList.push_back(100);
	myList.push_back(-99);
	myList.push_back(10);
	myList.push_back(0);

	std::list<int>::iterator it = myList.begin();
	std::list<int>::iterator ite = myList.end();

	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	--it;
	std::cout << "=======print list using iterator======" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	}


	std::string						words[5] = {"Hi", "Hello", "Bonjour", "Salut", "World"};
	MutantStack<std::string>		mstack2;
	std::list<std::string>			l;
	std::stack<std::string>			s2;
	for (int i = 0; i < 5; i++)
	{
		mstack2.push(words[i]);
		s2.push(words[i]);
		l.push_back(words[i]);
	}

	std::cout << "-------------------" << std::endl;
	std::cout << "Container size :" << std::endl;
	std::cout << "MutantStack : " << mstack2.size() << std::endl;
	std::cout << "Stack : " << s2.size() << std::endl;
	std::cout << "List : " << l.size() << std::endl;


	std::cout << "-------------------" << std::endl;
	std::cout << "Contents of MutantStack :" << std::endl;
	MutantStack<std::string>::iterator it2 = mstack2.begin();
	MutantStack<std::string>::iterator ite2 = mstack2.end();
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	std::cout << "-------------------" << std::endl;
	std::cout << "Contents of List :" << std::endl;
	std::list<std::string>::iterator it3 = l.begin();
	std::list<std::string>::iterator ite3 = l.end();
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
	
	std::cout << "-------------------" << std::endl;
	std::cout << "Contents of Stack :" << std::endl;
	while (!s2.empty())
	{
		std::cout << s2.top() << std::endl;
		s2.pop();
	}
	
	MutantStack<int> myStack(mstack);  // 5 default-constructed ints

  	//int i=0;

	std::cout << "=======print mstack using r iterator======" << std::endl;
  	MutantStack<int>::reverse_iterator rit = myStack.rbegin();
  	for (rit = myStack.rbegin(); rit!= myStack.rend(); ++rit)
    	std::cout << " " << *rit;
	std::cout << std::endl;;
	std::cout << "myStack contains:";
  	for (MutantStack<int>::iterator it = myStack.begin(); it != myStack.end(); ++it)
    	std::cout << " " << *it;
	std::cout << std::endl;;
	return 0;
}
