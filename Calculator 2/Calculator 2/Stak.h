#define STAK_H_INCLUDED

#include <iostream>

template < typename T >
struct list
{
    T id;
    list* next;
};

template < typename T >
void push(list<T>*& ptr, T x)
{
    list<T>* tmp = new(list<T>);
    tmp->id = x;
    tmp->next = ptr;
    ptr = tmp;
}

template < typename T >
void print(list<T>* ptr)
{
    while (ptr) {
        std::cout << ptr->id << " ->";
        ptr = ptr->next;
    }
}

template < typename T >
T pop(list<T>*& ptr)
{
    list<T>* tmp = ptr;
    ptr = ptr->next;
    T x = tmp->id;
    delete(tmp);

    return(x);
}

 // STAK_H_INCLUDED


