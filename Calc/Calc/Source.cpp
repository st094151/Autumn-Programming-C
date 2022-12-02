#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

bool IsDigit(char c)
{
	if ((c >= '0') && (c <= '9'))
	{
		return true;
	}
	else
	{
		return false;
	}
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

char* CutSubstring(string s, int StartPosition)
{
	char c;
	bool e = false;
	int j = 1;
	/*int n = 0;

	for (int i = StartPosition; i < s.length(); ++i)
	{
		c = s[i];

		if (c == '.')
		{
			++n;
		}
		else if (c == 'e')
		{
			e = true;
			++n;
		}
		else if (e)
		{
			e = false;
			++n;
		}
		else if (IsDigit(s[i]))
		{
			++n;
		}
		else
		{
			break;
		}
	}
*/
	char* result = new char[20];

	result[0] = s[StartPosition];

	for (unsigned int i = StartPosition + 1; i < s.length(); ++i)
	{
		c = s[i];
		
		if (c == '.')
		{
			result[j] = s[i];
			++j;
		}
		else if (c == 'e')
		{
			e = true;
			result[j] = s[i];
			++j;
		}
		else if (e)
		{
			e = false;
			result[j] = s[i];
			++j;
		}
		else if (IsDigit(s[i]))
		{
			result[j] = s[i];
			++j;
		}
		else
		{
			break;
		}
	}

	result[j] = '\0';

	return result;

	delete[]result;
}

int LengthofCutSubstring(string s, int StartPosition)
{
	bool e = false;
	char c = s[StartPosition];
	int n = 0;

	for (unsigned int i = StartPosition + 1; i < s.length(); ++i)
	{
		c = s[i];

		if (c == '.')
		{
			++n;
		}
		else if (c == 'e')
		{
			e = true;
			++n;
		}
		else if (e)
		{
			e = false;
			++n;
		}
		else if (IsDigit(s[i]))
		{
			++n;
		}
		else
		{
			break;
		}
	}

	return n;
}

double Calculating(string s)
{
	list<double>* X = NULL;
	list<char>* Y = NULL;
	char* str = new char[0];
	double result = 0;
	int i = 0;

	while ( (s[i] != '\0'))
	{
		if ( (IsDigit(s[i])) || ((i == 0) && (s[i] == '-')))
		{
			str = CutSubstring(s, i);
			cout << str << endl;
			double k = atof(str);
			push(X, k);
			i += LengthofCutSubstring(s, i);
		}
		else if ((i > 0) && (s[i - 1] == '(') && (s[i] == '-'))
		{
			str = CutSubstring(s, i);
			push(X, atof(str));
			i += LengthofCutSubstring(s, i);
		}
		else if (s[i] == '(')
		{
			push(Y, s[i]);
		}
		else if (s[i] != ')')
		{
			if (Y == nullptr)
			{
				push(Y, s[i]);
			}
			else
			{
				char Y_top = pop(Y);

				while ((Priority(Y_top) >= Priority(s[i])) && (Y != NULL))
				{
					double y = pop(X);
					double x = pop(X);
					if ((Y_top == '/') && (y == 0))
					{
						cout << "Attempt to divide by 0";
						return 0;
					}
					else
					{
						push(X, Operate(x, y, Y_top));
					}

					Y_top = pop(Y);
				}

				if (Priority(Y_top) >= Priority(s[i]))
				{
					double y = pop(X);
					double x = pop(X);
					if ((Y_top == '/') && (y == 0))
					{
						cout << "Attempt to divide by ";
						return 0;
					}
					else
					{
						push(X, Operate(x, y, Y_top));
					}
				}
				else
				{
					push(Y, Y_top);
				}

				if (s[i] != '=')
				{
					push(Y, s[i]);
				}
				
				if (s[i] == '=')
				{
					while (Y != NULL)
					{
						Y_top = pop(Y);
						double y = pop(X);
						double x = pop(X);
						if ((Y_top == '/') && (y == 0))
						{
							cout << "Attempt to divide by 0";
							return 0;
						}
						else
						{
							push(X, Operate(x, y, Y_top));
						}
					}
				}
			}
		}
		else
		{
			char c = pop(Y);

			while (c != '(')
			{
				double y = pop(X);
				double x = pop(X);
				if ((c == '/') && (y == 0))
				{
					cout << "Attempt to divide by 0";
					return 0;
				}
				else
				{
					push(X, Operate(x, y, c));
				}
				c = pop(Y);
			}
		}

		++i;
	}

	result = pop(X);

	return result;
}

int main()
{
	string s;

	cin >> s;

	if (s[s.length() - 1] != '=')
	{
		cout << "Invalid input" << endl;

		return EXIT_SUCCESS;
	}

	cout << "Result = " << Calculating(s) << endl;

	return EXIT_SUCCESS;
}