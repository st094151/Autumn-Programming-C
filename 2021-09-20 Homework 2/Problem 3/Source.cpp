#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int k = 0; //Количетсво котлет, которые можно обжаривать одновременно
	int m = 0; //Время на обжарку одной котлеты
	int n = 0; //Количество котлет, которые необходимо обжарить
	int result = 0;

	cin >> k;//f
	cin >> m;
	cin >> n;

	if (n > k) {
		result = 2 * n / k;
		if (2 * n % k != 0) {
			result++;
		}
	}
	else
	{
		result = 2;
	}

	result *= m;
	cout << result << endl;

	return EXIT_SUCCESS;
}