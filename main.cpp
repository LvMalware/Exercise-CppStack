/*
 * main.cpp -- applications main file
 *
 */
 
#include <iostream>
#include "stack.hpp"

int
main(int argc, char **argv)
{
	Stack <int> s(10);
	for (int i = 0; i< 10; i++)
		s.push(i);
	s.show();
	std::cout << "Last: " << s.pop() << std::endl;
	s.show();
	s.push(10);
	s.show();
	try {
		s.push(666);
	}
	catch (Exception &e)
	{
		e.show();
	}

	s.show();
	return 0;
}
