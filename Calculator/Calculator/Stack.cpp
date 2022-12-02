#include "Stack.h"

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Node<T> &node)
{
	stream << node.data;

	return stream;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Stack<T> &This_Stack)
{
	stream << "{ ";
	Node* temp = This_Stack.top;
	while (temp != nullptr)
	{
		stream << *temp << " ";
		temp = temp->next;
	}

	stream << " }";

	return stream;
}

template <typename T>
Stack<T>::~Stack()
{
	while (top != nullptr)
	{
		Pop();
	}
}

template <typename T>
void Stack<T>::Push(T element)
{
	top = new Node(element, top);
}

template <typename T>
T Stack<T>::Pop()
{
	if ( (top == nullptr))
	{
		return;
	}

	Node* temp = top;
	T value = top->data;
	top = top->next;
	//delete temp;

	return value;
}
