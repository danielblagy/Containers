#pragma once

#include <iostream>


template <class Type>
class Stack
{
private:
	Type* elements = 0;
	int max_index = -1;
	unsigned int capacity = 0;

public:
	Stack() {}

	~Stack()
	{
		delete[] elements;
	}

	void push(Type value)
	{
		if (max_index + 1 >= capacity)
		{
			reallocate();
		}
		max_index++;

		elements[max_index] = value;
	}

	Type top()
	{
		if (max_index < 0)
		{
			std::cout << "Stack is empty" << std::endl;
			return Type();
		}

		return elements[max_index];
	}

	void pop()
	{
		if (max_index < 0)
		{
			std::cout << "Stack is empty" << std::endl;
		}
		else
		{
			max_index--;
		}
	}

	unsigned int size()
	{
		return max_index + 1;
	}

private:
	void reallocate()
	{
		Type* new_elements = new Type[capacity * 2 + 1];

		capacity = capacity * 2 + 1;

		for (int i = 0; i <= max_index; i++)
			new_elements[i] = elements[i];

		delete[] elements;
		elements = new_elements;
	}
};