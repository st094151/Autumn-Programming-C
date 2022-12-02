#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

bool IsNumber(char c)
{
	if ((c >= '0') && (c <= '9'))
	{
		return true;
	}

	return false;
}

int Priority(char c)
{
	switch (c)
	{
	case '=':
		return 1;
	case '(':
		return 2;
	case '-':
		return 3;
	case '+':
		return 3;
	case '*':
		return 4;
	case '/':
		return 4;
	default:
		return 5;
	}
}

void PushingOperators(Stack<string> &X, Stack<char> &Y, char c)
{
	char Y_top = Y.Pop();
	string str = "";
	if (Y_top == '\0')
	{
		Y.Push(c);
		return;
	}
	if (Priority(Y_top) < Priority(c))
	{
		Y.Push(Y_top);
		Y.Push(c);
	}
	else
	{
		str.push_back(Y_top);
		X.Push(str);
		PushingOperators(X, Y, c);
	}
}

Stack<string> ReverseStack(Stack<string>& X)
{
	Stack<string> Y;
	string str = X.Pop();
	while (str != "")
	{
		Y.Push(str);
		str = X.Pop();
	}

	return Y;
}

Stack<string> Stack_Filling(string s)
{
	Stack<string> X;
	Stack<char> Y;
	string str = "";
	for (unsigned int i = 0; i < s.length(); ++i)
	{
		if (IsNumber(s[i]))
		{
			if (i > 0)
			{
				if (IsNumber(s[i - 1]))
				{
					str = X.Pop();	
				}
			}
			str.push_back(s[i]);
			X.Push(str);
			str = "";
		}
		else if (s[i] == '(')
		{
			Y.Push(s[i]);
		}
		else if (s[i] != ')')
		{
			PushingOperators(X, Y, s[i]);
		}
		else
		{
			char c = Y.Pop();
			while (c != '(')
			{
				str[0] = c;
				X.Push(str);
				c = Y.Pop();
			}
		}
	}

	X.Push("=");
	return X;
}

int Calculating(Stack& X)
{
	int result = 0;
	int temp = 0;
	char c = X.Pop();
	while (c != '\0')
	{

	}
}

int main(int argc, char* argv[])
{
	string s = "7+((6+2)/(1+1)-3)*(9+(2+5)*2)=";
	
	//Stack<string> st = Stack_Filling(s);

	//st = ReverseStack(st);

	//cout <<  st << endl;

	return EXIT_SUCCESS;
}