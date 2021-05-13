#pragma once


template <class Type>
class LinkedList
{
private:
	struct Node
	{
		Node* next = 0;
		Type value;
	};

public:
	class iterator
	{
	private:
		Node* current = 0;

	public:
		void next()
		{
			current = current->next;
		}

		bool end()
		{
			return current == 0;
		}

		Type value()
		{
			return current->value;
		}

	private:
		iterator(Node* node)
		{
			current = node;
		}

		friend LinkedList;
	};

private:
	Node* front = 0;

public:
	~LinkedList()
	{
		while (front)
		{
			Node* n = front;
			front = front->next;
			delete n;
		}
	}
	
	void insert_front(Type value)
	{
		Node* node = new Node();

		node->next = front;
		node->value = value;

		front = node;
	}

	void insert_after(iterator it, Type value)
	{
		Node* node = it.current;

		Node* new_node = new Node();

		new_node->next = node->next;
		new_node->value = value;

		node->next = new_node;
	}

	void remove_after(iterator it)
	{
		Node* node = it.current;
		
		Node* node_to_remove = node->next;
		
		node->next = node_to_remove->next;
		
		delete node_to_remove;
	}

	iterator get_interator()
	{
		return iterator(front);
	}
};