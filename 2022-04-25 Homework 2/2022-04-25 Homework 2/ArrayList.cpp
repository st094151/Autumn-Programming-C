#include "ArrayList.h"

void QuickSort(int* a, int size) {
	//Указатели в начало и в конец массива
	int i = 0;
	int j = size - 1;

	//Центральный элемент массива
	int mid = a[size / 2];

	//Делим массив
	do {
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (a[i] < mid) {
			i++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (a[j] > mid) {
			j--;
		}

		//Меняем элементы местами
		if (i <= j) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		QuickSort(a, j + 1);
	}
	if (i < size) {
		//"Правый кусок"
		QuickSort(&a[i], size - i);
	}
}

void ArrayList::expand(int count)
{
	int* newdata = new int[count + this->capacity];

	for (int i = 0; i < this->capacity; ++i)
	{
		newdata[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newdata;
	this->capacity += count;
}

void ArrayList::swap(int posi, int posj)
{
	int i = posi;
	int j = posj;

	if (posi < 0)
	{
		i = 0;
	}
	else if (posi >= this->count)
	{
		i = count - 1;
	}

	if (posj < 0)
	{
		j = 0;
	}
	else if (posj >= this->count)
	{
		j = count - 1;
	}

	int temp = this->data[i];
	this->data[i] = this->data[j];
	this->data[j] = temp;
}

int ArrayList::ind(int index)
{
	if (index < 0)
	{
		pushbegin(0);
		return 0;
	}
	if (index >= this->count)
	{
		pushend(0);
		return (this->count - 1);
	}

	return index;
}

ArrayList::ArrayList(int capacity)
{
	this->capacity = capacity;
	this->count = 0;
	this->data = new int[capacity];
}

ArrayList::ArrayList(const ArrayList& list)
{
	this->capacity = list.count;
	this->count = list.count;
	this->data = new int[list.count];
	for (int i = 0; i < list.count; ++i)
	{
		this->data[i] = list.data[i];
	}

}

ArrayList::~ArrayList()
{
	this->count = 0;
	this->capacity = 0;
	for (int i = 0; i < this->capacity; ++i)
	{
		this->data[i] = 0;
	}
	delete[] this->data;
}

void ArrayList::pushend(int element)
{
	if (this->count == this->capacity)
	{
		expand(this->capacity);
	}
	this->data[this->count] = element;
	this->count++;
}

void ArrayList::pushbegin(int element)
{
	if (this->count == this->capacity)
	{
		expand(this->capacity);
	}

	for (int i = this->count - 1; i >= 0; --i)
	{
		this->data[i + 1] = this->data[i];
	}

	this->data[0] = element;
	this->count++;
}

void ArrayList::insert(int element, int position)
{
	if (this->count == this->capacity)
	{
		expand(this->capacity);
	}

	for (int i = this->count - 1; i >= position; --i)
	{
		this->data[i + 1] = this->data[i];
	}

	this->data[position] = element;
	this->count++;
}

int ArrayList::extractbegin()
{
	int result = this->data[0];
	this->count--;
	for (int i = 0; i < this->count; i++)
	{
		this->data[i] = this->data[i + 1];
	}

	return result;
}

int ArrayList::extractend()
{
	this->count--;
	return this->data[this->count];
}

int ArrayList::extract(int position)
{
	int result = this->data[position];
	this->count--;

	for (int i = position; i < this->count; ++i)
	{
		this->data[i] = this->data[i + 1];
	}

	return result;
}

int& ArrayList::operator[](int pos)
{
	return data[ind(pos)];
}

void ArrayList::sort()
{
	QuickSort(this->data, this->count);
}

std::ostream& operator<<(std::ostream& stream, ArrayList& list)
{
	stream << "[" << list.count << "/" << list.capacity << "] {";
	if (list.count == 0)
	{
		stream << "EMPTY";
	}
	else
	{
		for (int i = 0; i < list.count - 1; ++i)
		{
			stream << list.data[i] << ", ";
		}
		stream << list.data[list.count - 1];
	}
	stream << "}";
	return stream;
}
