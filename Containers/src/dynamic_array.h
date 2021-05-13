#pragma once

#include <exception>


class invalid_index : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Object of that index doesn't exist";
	}
} invalid_index_exception;


template <class Type>
class DynamicArray
{
private:
	Type* elements = 0;
	int max_index = -1;
	unsigned int capacity = 0;

public:
	DynamicArray() {}

	~DynamicArray()
	{
		delete[] elements;
	}

	void push_back(Type value)
	{
		if (max_index + 1 >= capacity)
		{
			reallocate();
		}
		max_index++;

		elements[max_index] = value;
	}

	void push(unsigned int index, Type value)
	{
		if (index > max_index)
			throw invalid_index_exception;

		if (max_index + 1 >= capacity)
		{
			reallocate();
		}
		max_index++;

		for (int i = max_index; i > index; i--)
			elements[i] = elements[i - 1];

		elements[index] = value;
	}

	Type get(unsigned int index)
	{
		if (index <= max_index)
			return elements[index];
		else
			throw invalid_index_exception;
	}

	void remove(unsigned int index)
	{
		if (index <= max_index)
		{
			for (int i = index; i < max_index; i++)
				elements[i] = elements[i + 1];

			max_index--;
		}
		else
			throw invalid_index_exception;
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