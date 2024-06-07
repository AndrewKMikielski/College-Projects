// Andrew Mikielski Project 3
#ifndef MIKIELSKI_LIST_H
#define MIKIELSKI_LIST_H

#include "Record.h"

class ListNode
{
    public:
        Record data;
        ListNode *pNext;
        ListNode() {pNext = NULL;};
};

class List
{
    private:
        ListNode *pFirst, *pLast, *pCurrent, *pPrev;
        void swapNode(ListNode *p1, ListNode *p2);
        void swapList(List& L1, List& L2);

    public:
        List();
        List(const List &L);
        List& operator=(List L);
        ~List();
        void append(Record d);
        bool goToFirst();
        bool goToNext();
        bool getCurrent(Record &d);
        bool deleteCurrent();
        bool search(Record d);
        void sort();
        void merge(List &lst);
};

#include "List.cpp"
#endif // MIKIELSKI_LIST_H
