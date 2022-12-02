#include <iostream>
#include <string>
#include "Stak.h"

using namespace std;

bool IsNumber(char c)
{
	if ((c >= '0') && (c <= '9'))
	{
		return true;
	}

	return false;
}

double Char_To_Double(char c)
{
	double result = c - '0';

	return result;
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

/*
void PushingOperators(list<char>* X, list<char>* Y, char c)
{
	if (Y == NULL)
	{
		push(Y, c);
		return;
	}
	else
	{
		char Y_top = pop(Y);
		if (Priority(Y_top) < Priority(c))
		{
			push(Y, Y_top);
			push(Y, c);
		}
		else
		{
			push(X, ' ');
			push(X, Y_top);
			PushingOperators(X, Y, c);
		}
	}
}
*/

string Stack_Filling(string s)
{
	list<char>* X = NULL;
	list<char>* Y = NULL;

	for (unsigned int i = 0; i < s.length(); ++i)
	{
		if (IsNumber(s[i]))
		{

			if (i > 0)
			{
				if (IsNumber(s[i - 1]))
				{
					push(X, s[i]);
				}
				else
				{
					push(X, ' ');
					push(X, s[i]);
				}
			}
			else
			{
				push(X, s[i]);
			}
		}
		else if (s[i] == '(')
		{
			push(Y, s[i]);
		}
		else if (s[i] != ')')
		{
			if (Y == NULL)
			{
				push(Y, s[i]);
			}
			else
			{
				char Y_top = pop(Y);

				while ( (Priority(Y_top) >= Priority(s[i])) && (Y != NULL) )
				{
					push(X, ' ');
					push(X, Y_top);
					Y_top = pop(Y);
				}

				if (Priority(Y_top) >= Priority(s[i]))
				{
					push(X, ' ');
					push(X, Y_top);
				}
				else
				{
					push(Y, Y_top);
				}

				push(Y, s[i]);

				if (s[i] == '=')
				{
					while (Y != NULL)
					{
						Y_top = pop(Y);
						push(X, ' ');
						push(X, Y_top);
					}
				}

			}
		}
		else
		{
			char c = pop(Y);
			while (c != '(')
			{
				push(X, ' ');
				push(X, c);
				c = pop(Y);
			}
		}
	}

	string result = "";
	char c = pop(X);

	while (X != NULL)
	{
		result.push_back(c);

		c = pop(X);
	}

	result.push_back(c);

	return result;
}

string ReverseString(string s)
{
	string result = s;

	for (unsigned i = 0; i < s.length(); ++i)
	{
		result[i] = s[s.length() - i - 1];
	}

	return result;
}

double Operate(double x, double y, char c)
{
	switch (c)
	{
	case '-':
		return (x - y);
	case '+':
		return (x + y);
	case '*':
		return (x * y);
	default:
		return (x / y);
	}
}

double Power(int n)
{
	double result = 1;
	for (int i = 0; i < n; ++i)
	{
		result *= 10;
	}
	return result;
}

double Calculating(string s)
{
	list<double>* X = NULL;
	double y = 0;
	double temp1 = 0;
	double temp2 = 0;
	int power_10 = 0;
	unsigned i = 0;

	while ( i < s.length())
	{
		if (IsNumber(s[i]))
		{
			while ( (s[i] != ' ') && (s[i] != '='))
			{
				if (s[i] == '.')
				{
					++power_10;
					y = y + Char_To_Double(s[i]) / (Power(power_10));
				}
				else
				{
					y = y * 10 + Char_To_Double(s[i]);
				}
				++i;
			}
			push(X, y);
			power_10 = 0;
			y = 0;
		}
		else if (s[i] != ' ')
		{
			if (s[i] == '=')
			{
				return pop(X);
			}

			temp1 = pop(X);
			temp2 = pop(X);

			if ((s[i] == '/') && (temp1 == 0))
			{
				cout << "Attempt to divide by ";
				return 0;
			}

			push (X, Operate(temp2, temp1, s[i]));
		}

		++i;
	}
}

/*
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


void PushingOperator(Stack<string>& X, Stack<char>& Y, char c)
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
*/

int main(int argc, char* argv[])
{

	string s;

	cin >> s;

	cout << s << endl;

	//s = "7+((6+2)/(1+1)-3)*(9+(2+5)*2)=";

	if (s[s.length() - 1] != '=')
	{
		cout << "Invalid input" << endl;

		return EXIT_SUCCESS;
	}

	string str = Stack_Filling(s);

	cout << str << endl;

	str = ReverseString(str);

	cout << str << endl;

	double k = Calculating(str);

	cout << k << endl;
	
	/*
    list<char>* Y = NULL;
    list<double>* X = NULL;
    list<int>* Z = NULL;

    push(Y, 'a');
    push(Y, '$');
    push(Y, '(');
    print(Y);
    cout << "\n\n";

    push(X, 0.2);
    push(X, 0.23);
    push(X, 0.12);
    push(X, 0.222);
    print(X);
    cout << "\n\n";

    push(Z, 1);
    push(Z, 2);
    push(Z, 3);
    push(Z, 4);
    push(Z, 4);
    push(Z, 1);
    print(Z);
    cout << "\n\n";
    */

    return EXIT_SUCCESS;
}
