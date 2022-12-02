#include <iostream>
#include"LinkedList.h"

using namespace std;

int main()
{
	LinkedList list;
	
	/*cout << list << endl;
	list.pushHead(0);
	list.pushTail(1);
	list.pushTail(2);
	list.pushHead(-1);
	list.pushHead(-2);
	list.pushHead(-2);
	list.pushHead(-2);
	list.pushHead(-2);
	list.pushHead(-2);
	list.pushHead(-2);
	list.pushTail(2);
	list.pushTail(2);
	list.pushTail(2);
	list.pushTail(0);
	list.pushTail(2);
	list.insert(0, -152);
	list.insert(0, 6);
	cout << list << endl;

	list.insert(17, 2);
	cout << list << endl;
	list.insert(29, -2);
	cout << list << endl;
	list.insert(18, -152);
	cout << list << endl;
	list.insert(19, 0);
	cout << list << endl;
	list.insert(100, 200);
	cout << list << endl;

	cout << "poped : " << list.popHead() << endl;
	cout << "poped : " << list.popHead() << endl;
	cout << "poped : " << list.popTail() << endl;
	cout << "poped : " << list.popTail() << endl;
	cout << list << endl;

	cout << "extracted : " << list.extract(150) << endl;
	cout << list << endl;
	cout << "extracted : " << list.extract(2) << endl;
	cout << list << endl;

	cout << "poped : " << list.popHead() << endl;
	cout << "poped : " << list.popTail() << endl;
	cout << list << endl;

	
	list.insert(11, 15);
	cout << list << endl;
	list.insert(22, 3);
	cout << list << endl;
	list.insert(33, 2);
	cout << list << endl;
	list.insert(44, 7);
	cout << list << endl;
	list.insert(55, 4);
	cout << list << endl;
	list.insert(66, 6);
	cout << list << endl;

	cout << "SWAP -15 150" << endl;
	list.swap(-15, 150);
	cout << list << endl;

	cout << "SWAP -4 3" << endl;
	list.swap(-4, 3);
	cout << list << endl;

	cout << "SWAP 2 4" << endl;
	list.swap(2, 4);
	cout << list << endl;

	cout << "SWAP 4 3" << endl;
	list.swap(4, 3);
	cout << list << endl;

	cout << "Removing identical" << endl;
	list.RemovingIdentical();
	cout << list << endl;
	*/

	char x = 0;
	int number = 0;
	int position = 0;
	int index = 0;
	bool exit = false;

	cout << "Menu:" << endl;
	cout << "1 - pushHead" << endl;
	cout << "2 - pushTail" << endl;
	cout << "3 - popHead" << endl;
	cout << "4 - popTail" << endl;
	cout << "5 - insert" << endl;
	cout << "6 - extract" << endl;
	cout << "7 - Swap" << endl;
	cout << "8 - removing identoical" << endl;
	cout << "Any other numbers - end this programm" << endl;


	while (!exit)
	{
		cin >> x;

		switch (x)
		{
		case '1':
		{
			cout << "Write a number to push it in head" << endl;
			cin >> number;
			list.pushHead(number);

			cout << list << endl;
			break;
		}
		case '2':
		{
			cout << "Write a number to push it in tail" << endl;
			cin >> number;
			list.pushTail(number);

			cout << list << endl;
			break;
		}
		case '3':
		{
			cout << "This number was poped from head " << list.popHead() << endl;

			cout << list << endl;
			break;
		}
		case '4':
		{
			cout << "This number was poped from tail " << list.popTail() << endl;

			cout << list << endl;

			break;
		}
		case '5':
		{
			cout << "Write a number and position to insert" << endl;
			cin >> number >> position;
			list.insert(number, position);

			cout << list << endl;
			break;
		}
		case '6':
		{
			cout << "Write a position to extract" << endl;
			cin >> position;
			cout << "This number was extracted " << list.extract(position) << endl;

			cout << list << endl;
			break;
		}
		case '7':
		{
			cout << "Write two positions to swap elements" << endl;
			cin >> position >> index;
			list.swap(position, index);

			cout << list << endl;
			break;
		}
		case '8':
		{
			cout << "Remove identical numbers" << endl;
			list.RemovingIdentical();

			cout << list << endl;
			break;
		}
		default:
			exit = true;
			break;
		}
	}

	return EXIT_SUCCESS;
}