#pragma once

#include <iostream>

#include "dynamic_array.h"

#include <string>


void test_da()
{
	DynamicArray<std::string> da;
	std::string e = ".";
	while (e[0] != '8')
	{
		std::cin >> e;
		da.push_back(e);
		for (int i = 0; i < da.size(); i++)
			std::cout << da.get(i) << "  ";
		std::cout << std::endl;
	}

	da.push(3, "77");

	for (int i = 0; i < da.size(); i++)
		std::cout << da.get(i) << "  ";
	std::cout << std::endl;

	da.push(5, "120");

	for (int i = 0; i < da.size(); i++)
		std::cout << da.get(i) << "  ";
	std::cout << std::endl;

	da.remove(2);

	for (int i = 0; i < da.size(); i++)
		std::cout << da.get(i) << "  ";
	std::cout << std::endl;

	da.remove(5);

	for (int i = 0; i < da.size(); i++)
		std::cout << da.get(i) << "  ";
	std::cout << std::endl;

	da.remove(1);

	for (int i = 0; i < da.size(); i++)
		std::cout << da.get(i) << "  ";
	std::cout << std::endl;

	da.get(100);
}