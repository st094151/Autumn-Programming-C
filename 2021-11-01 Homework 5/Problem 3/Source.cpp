#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	int result = 0;
	unsigned int added_bit = 1; //add 1 to reverse n if n < 0

	cin >> n;
	
	result = n;
	if (n < 0)
	{
		result = ~ n;
		int i = 0;
		while ((added_bit != 0) && (i < sizeof(int) * 8 - 1))//Add 1 to reverse n
		{
			unsigned int current_bit = 0; //Current bit of result
			current_bit = result << (sizeof(int) * 8 - (i + 1));
			current_bit = current_bit >> (sizeof(int) * 8 - 1);
			current_bit = current_bit << i;
			result = result | added_bit;
			added_bit = current_bit & added_bit;
			if (added_bit != 0)
			{
				result = result >> i + 1;
				result = result << i + 1;
			}
			added_bit = added_bit << 1;
			++i;
		}
	}



	cout << result << endl;

	return EXIT_SUCCESS;
}