#pragma once

#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* next;
	Node(T s, Node* next = nullptr) : data(s), next(next){}
	Node(const Node& node) : data(node.data), next(node.next){}
	
	~Node()
	{
		next = nullptr;
	}

	template <typename T>
	friend std::ostream& operator<<(std::ostream& stream, const Node<T>& node);
};

template <typename T>
class Stack
{
private:
	Node<T>* top;

public:
	Stack<T>() : top(nullptr) {}

	~Stack<T>();

	void Push(T element);

	T Pop();

	friend std::ostream& operator<<(std::ostream& stream, const Stack& This_Stack);
};