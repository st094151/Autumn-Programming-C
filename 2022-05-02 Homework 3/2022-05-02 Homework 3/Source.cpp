#include <iostream>
#include"LinkedList.h"

using namespace std;

int main()
{
	LinkedList list;
	cout << list << endl;
	list.pushHead(0);
	list.pushTail(1);
	list.pushTail(2);
	list.pushHead(-1);
	list.pushHead(-2);
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

	cout << "poped : " << list.popHead() << endl;
	cout << "poped : " << list.popTail() << endl;
	cout << list << endl;

	cout << "SWAP" << endl;
	list.swap(0, 2);
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

	return EXIT_SUCCESS;
}