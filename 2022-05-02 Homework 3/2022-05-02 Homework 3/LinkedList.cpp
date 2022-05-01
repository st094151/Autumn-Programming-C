#include "LinkedList.h"

std::ostream& operator<<(std::ostream& stream, const Node& node)
{
    stream << node.data;

    return stream;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
{
    stream << "[" << list.count << "] : { ";
    Node* temp = list.head;
    while (temp != nullptr)
    {
        stream << *temp << " ";
        temp = temp->next;
    }

    stream << "}";
    
    return stream;
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        popHead();
    }
}

void LinkedList::pushHead(int element)
{
    head = new Node(element, head);
    if (tail == nullptr)
    {
        tail = head;
    }

    ++count;
}

void LinkedList::pushTail(int element)
{
    if (tail == nullptr)
    {
        return pushHead(element);
    }

    tail->next = new Node(element);
    tail = tail->next;

    ++count;
}

void LinkedList::insert(int element, int index)
{
    if (index >= count)
    {
        return pushTail(element);
    }
    else if (index <= 0)
    {
        return pushHead(element);
    }

    Node* temp = head;

    for (int i = 0; i < index - 1; ++i)
    {
        temp = temp->next;
    }

    temp->next = new Node(element, temp->next);

    ++count;
}

int LinkedList::extract(int index)
{
    if (index <= 0)
    {
        return popHead();
    }
    else if (index >= count)
    {
        return popTail();
    }

    Node* temp = head;

    for (int i = 0; i < index - 1; ++i)
    {
        temp = temp->next;
    }
    
    --count;

    int value = temp->next->data;
    Node* tempal = temp->next;
    temp->next = temp->next->next;
    delete tempal;
    
    return value;
}

void LinkedList::swap(int index1, int index2)
{
    if (index1 > index2)
    {
        int n = index1;
        index1 = index2;
        index2 = n;
    }

    if (index1 < 0)
    {
        index1 = 0;
    }

    if (index2 >= count)
    {
        index2 = count - 1;
    }

    if (index1 == index2)
    {
        return;
    }

    Node* prev1 = head;
    Node* curr1 = head;

    for (int i = 0; i < index1; ++i)
    {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    Node* prev2 = head;
    Node* curr2 = head;

    for (int i = 0; i < index2; ++i)
    {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (prev1 != curr1)
    {
        prev1->next = curr2;
    }
    else
    {
        head = curr2;
    }

    if (prev2 != curr2)
    {
        prev2->next = curr1;
    }
    else
    {
        head = curr2;
    }

    Node* temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;

    tail = curr1;

}

int LinkedList::popHead()
{
    if (head == nullptr)
    {
        return 0;
    }

    --count;
    Node* temp = head;
    int value = head->data;
    head = head->next;
    delete temp;

    if (head == nullptr)
    {
        tail = nullptr;
    }


    return value;
}

int LinkedList::popTail()
{
    if (tail == nullptr)
    {
        return 0;
    }

    if (head == tail)
    {
        return popHead();
    }

    Node* temp = head;

    while (temp->next != tail)
    {
        temp = temp->next;
    }

    --count;
    int value = tail->data;
    delete tail;
    tail = temp;
    tail->next = nullptr;

    return value;
}
