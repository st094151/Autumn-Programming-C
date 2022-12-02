#include <iostream>
#include <stdlib.h>

using namespace std;

int tab = 0;
int verticesnumber = 0;

struct link
{
	int id;
	int weight;

	link* left;
	link* right;
};

void Add (int data, link*& vertex)
{
	if (!vertex)
	{
		vertex = new link;
		vertex->id = data;
		vertex->weight = rand() % 3 - 1;
		vertex->left = nullptr;
		vertex->right = nullptr;

		return;
	}
	else if (vertex->id > data)
	{
		Add(data, vertex->left);
	}
	else
	{
		Add(data, vertex->right);
	}
}

void print(link* vertex)
{
	if (!vertex)
	{
		return;
	}

	tab += 5;
	print(vertex->left);

	for (int i = 0; i < tab; ++i)
	{
		cout << " ";
	}

	cout << vertex->id << "(" <<vertex->weight << ")" << endl;

	print(vertex->right);
	tab -= 5;
	return;
}

void Tree_traversal(link*& vertex)
{
	if (vertex == nullptr)
	{
		return;
	}

	if (vertex->weight != 0)
	{

		if (((vertex->left == NULL) && (vertex->right != 0)) || ((vertex->right == NULL) && (vertex->left != 0)))
		{
			cout << vertex->id << "(" << vertex->weight << ")" << endl;
		}

	}

	Tree_traversal(vertex->left);
	Tree_traversal(vertex->right);
}

void Inorder(link*& vertex)
{
	if (vertex == nullptr)
	{
		return;
	}

	Inorder(vertex->left);

	cout << vertex->id << endl;

	Inorder(vertex->right);
}

void Preorder(link*& vertex)
{
	if (vertex == nullptr)
	{
		return;
	}

	cout << vertex->id << endl;

	Preorder(vertex->left);
	Preorder(vertex->right);
}

void Postorder(link*& vertex)
{
	if (vertex == nullptr)
	{
		return;
	}

	Postorder(vertex->left);
	Postorder(vertex->right);

	cout << vertex->id << endl;
}

/*
void Add_Element(int data, link*& vertex)
{
	if (!vertex)
	{
		vertex = new link;
		vertex->id = data;
		vertex->left = nullptr;
		vertex->right = nullptr;
		
		return;
	}
	else
	{
		if (data < vertex->id)
		{
			Add_Element(data, vertex->left);
		}
		else if (data > vertex->id)
		{
			Add_Element(data, vertex->right);
		}
	}
}
*/

void Remove_Tree(link* vertex)
{
	if (!vertex)
	{
		return;
	}

	Remove_Tree(vertex->left);
	Remove_Tree(vertex->right);

	delete vertex;

	return;
}

link* Delete_Element(int data, link*& vertex)
{
	if (vertex == nullptr)
	{
		return vertex;
	}

	if (data == vertex->id)
	{
		link* temp;

		if (vertex->right == nullptr)
		{
			temp = vertex->left;
		}
		else
		{
			link* tempal = vertex->right;

			if (tempal->left == nullptr)
			{
				tempal->left = vertex->left;
				temp = tempal;
			}
			else
			{
				link* pointer = tempal->left;

				while (pointer->left != nullptr)
				{
					tempal = pointer;
					pointer = tempal->left;
				}

				tempal->left = pointer->right;
				pointer->left = vertex->left;
				pointer->right = vertex->right;
				temp = pointer;
			}
		}
		delete vertex;
		
		return temp;
	}
	else if (data < vertex->id)
	{
		vertex->left = Delete_Element(data, vertex->left);
	}
	else
	{
		vertex->right = Delete_Element(data, vertex->right);
	}
	return vertex;
}

int main(int argc, char* argv[])
{
	link* Root = nullptr;

	srand(time(NULL));

	char x = 0;
	int number = 0;
	int element = 0;
	int index = 0;
	bool exit = false;

	cout << "Menu:" << endl;
	cout << "1 - Add a few random elements in a tree" << endl;
	cout << "2 - Print Tree" << endl;
	cout << "3 - Inorder tree traversal" << endl;
	cout << "4 - Preorder tree traversal" << endl;
	cout << "5 - Postorder tree traversal" << endl;
	cout << "6 - Add element to the tree" << endl;
	cout << "7 - Delete element from the tree" << endl;
	cout << "8 - Print vertices with exactly one child and nonzero weight" << endl;
	cout << "Any other numbers - end this programm" << endl;

	while (!exit)
	{
		cin >> x;

		switch (x)
		{
		case '1':
		{
			cout << "Write a number of random elements:" << endl;
			cin >> number;

			for (int i = 0; i < number; ++i)
			{
				Add(rand() % 100, Root);
			}

			print(Root);

			break;
		}
		case '2':
		{
			print(Root);

			break;
		}
		case '3':
		{
			Inorder(Root);

			break;
		}
		case '4':
		{
			Preorder(Root);

			break;
		}
		case '5':
		{
			Postorder(Root);

			break;
		}
		case '6':
		{
			cout << "Write a number to add in a tree:" << endl;
			cin >> element;
			Add(element, Root);
			print(Root);

			break;
		}
		case '7':
		{
			cout << "Write a number to remove from a tree:" << endl;
			cin >> element;
			Root = Delete_Element(element, Root);
			print(Root);
			
			break;
		}
		case '8':
		{
			Tree_traversal(Root);

			break;
		}
		default:
			exit = true;
			break;
		}
	}

	return EXIT_SUCCESS;
}