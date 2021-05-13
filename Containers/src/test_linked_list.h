#pragma once

#include <iostream>
#include <string>

#include "linked_list.h"


void print_list(LinkedList<std::string>& l)
{
	// print out the list
	LinkedList<std::string>::iterator it = l.get_interator();
	while (!it.end())
	{
		std::cout << it.value() << "  ";
		it.next();
	}
	std::cout << std::endl;
}

void test_ll()
{
	LinkedList<std::string> l;
	std::string e = ".";
	while (e[0] != '8')
	{
		std::cin >> e;
		l.insert_front(e);
		
		print_list(l);
	}

	LinkedList<std::string>::iterator it = l.get_interator();

	it.next();
	l.insert_after(it, "insertion_1");
	print_list(l);

	l.remove_after(it);
	print_list(l);
}