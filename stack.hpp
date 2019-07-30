/*
 * stack.hpp -- header/source for stack data structure
 *
 * Copyright (c) 2019 Lucas V. Araujo <lucas.vieira.ar@protonmail.com>
 *
 * This program is a free software, distributed under the GNU GPLv3.0+
 *
 */


#include <iostream>
#include "exception.h"

#ifndef  _STACK_HPP
#define  _STACK_HPP

using std::cout;
using std::endl;

#ifndef NULL
#define NULL 0
#endif

template <typename T>
class Stack
{
private:
	struct Item
	{
		T     data;
		Item *before;
	};
	Item *first;
	Item *last;
	unsigned count;
	unsigned max;

	void
	init(unsigned maxCount)
	{
		count = 0;
		first = NULL;
		last  = NULL;
		max   = maxCount;
	}
	
public:

	Stack()
	{
		init(1);
	}
	Stack(unsigned maximum)
	{
		init(maximum);
	}

	~Stack()
	{
		clear();
	}

	bool
	empty()
	{
		return (first == NULL);
	}

	bool
	full()
	{
		return (count == max);
	}

	unsigned
	getCount()
	{
		return count;
	}

	T
	pop()
	{
		if (empty())
			throw Exception(__FILE__, "stack is empty", __LINE__, -1);
		T data     = last->data;
		Item *item = last;
		last       = item->before;
		if (last   == NULL)
		{
			first  = 0;
		}
		count --;
		delete item;
		return data;
	}
	
	void
	push(T data)
	{
		if (full())
			throw Exception(__FILE__, "stack is full", __LINE__, 1);
			
		Item *item   = new Item;
		item->before = NULL;
		item->data   = data;
		count ++;
		if (!first)
		{
			first = last = item;
			return ;
		}

		item->before = last;
		last         = item;
	}
	void
	show()
	{
		Item *item = last;
		while (item)
		{
			cout << item->data;
			if (item->before)
			{
				cout << ", ";
			}
			else
			{
				cout << endl;
			}
			item = item->before;
		}
	}
	
	void
	clear()
	{
		Item *item = last;
		Item *next;
		while (item)
		{
			next = item->before;
			delete item;
			item = next;
		}
		count = 0;
	}
};

#endif /*_STACK_HPP*/
