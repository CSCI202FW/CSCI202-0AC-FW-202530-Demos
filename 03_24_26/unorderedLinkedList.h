#ifndef UNORDERED_H
#define UNORDERED_H
#include "linkedlist.h"

template <class t>
class unorderedLinkedList : public linkedListType<t>
{
public:
    enum directionType
    {
        FORWARD,
        BACKWARD
    };
    unorderedLinkedList(directionType = FORWARD);
    void insert(const t &newInfo);
    void deleteNode(const t &deleteItem);
    bool search(const t &searchItem) const;

private:
    directionType direction;
    void insertFirst(const t &newInfo);
    void insertLast(const t &newInfo);
};

template <class t>
unorderedLinkedList<t>::unorderedLinkedList(directionType d) : direction(d)
{
}
#endif