// Andrew Mikielski Project 3
List::List()
{
    pFirst = NULL;
    pLast = NULL;
    pCurrent = NULL;
    pPrev = NULL;
}

List::List(const List &L)
{
    pFirst = NULL;
    pLast = NULL;
    pCurrent = NULL;
    pPrev = NULL;

    ListNode *pCurr = L.pFirst;

    while(pCurr != NULL)
    {
        append(pCurr->data);
        pCurr = pCurr->pNext;
    }
}

void List::swapList(List& L1, List& L2)
{
    using std::swap;
    swap(L1.pFirst, L2.pFirst);
    swap(L1.pLast, L2.pLast);
    swap(L1.pCurrent, L2.pCurrent);
    swap(L1.pPrev, L2.pPrev);
}

List& List::operator=(List L)
{
    swapList(*this, L);
    return *this;
}

List::~List()
{
    goToFirst();
    while(deleteCurrent())
        goToFirst();
}

void List::append(Record d)
{
    ListNode *pNewNode = new ListNode();
    pNewNode->data = d;
    if(pFirst == NULL)
    {
        pFirst = pNewNode;
        pLast = pNewNode;
        return;
    }
    pLast->pNext = pNewNode;
    pLast = pNewNode;
}

bool List::goToFirst()
{
    pPrev = NULL;
    if(pFirst == NULL)
        return false;

    pCurrent = pFirst;
    return true;
}

bool List::goToNext()
{
    if(pCurrent == NULL)
        return false;
    pPrev = pCurrent;
    pCurrent = pCurrent->pNext;
    return true;
}

bool List::getCurrent(Record &d)
{
    if(pCurrent == NULL)
        return false;
    d = pCurrent->data;
    return true;
}

bool List::deleteCurrent()
{
    if(pCurrent == NULL)
        return false;
    if(pCurrent == pFirst)
    {
        pFirst = pFirst->pNext;
        if(pLast == pCurrent)
            pLast = NULL;
        delete pCurrent;
    }
    else
    {
        pPrev->pNext = pCurrent->pNext;
        if(pLast == pCurrent)
            pLast = pPrev;
        delete pCurrent;
    }
    pCurrent = NULL;
    pPrev = NULL; // Is this line logically okay due to the pPrev logic in the else() block?
    return true;
}

bool List::search(Record d)
{
    goToFirst();
    Record data;
    while(getCurrent(data))
    {
        if(data == d)
            return true;
        goToNext();
    }
    return false;
}

void List::swapNode(ListNode *p1, ListNode *p2)
{
    Record temp = p1->data;
    p1->data = p2->data;
    p2->data = temp;
}

void List::merge(List &lst)
{
    Record d, d1, d2;
    lst.goToFirst();
    if(!lst.getCurrent(d))
        return;
    lst.goToNext();
    if(!lst.getCurrent(d))
        return;
    List lst1, lst2;
    lst.goToFirst();
    while(lst.getCurrent(d))
    {
        lst1.append(d);
        lst.deleteCurrent();
        lst.goToFirst();
        if(lst.getCurrent(d))
        {
            lst2.append(d);
            lst.deleteCurrent();
            lst.goToFirst();
        }
        merge(lst1);
        merge(lst2);
    }
    lst1.goToFirst();
    lst2.goToFirst();
    while((lst1.getCurrent(d1)) && (lst2.getCurrent(d2)))
    {
        if(d1 < d2)
        {
            lst.append(d1);
            lst1.deleteCurrent();
            lst1.goToFirst();
        }
        else
        {
            lst.append(d2);
            lst2.deleteCurrent();
            lst2.goToFirst();
        }
    }
    while(lst1.getCurrent(d1))
    {
        lst.append(d1);
        lst1.deleteCurrent();
        lst1.goToFirst();
    }
    while(lst2.getCurrent(d2))
    {
        lst.append(d2);
        lst2.deleteCurrent();
        lst2.goToFirst();
    }
}

void List::sort()
{
    List lst;
    Record d;
    goToFirst();
    while(getCurrent(d))
    {
        lst.append(d);
        deleteCurrent();
        goToFirst();
    }
    merge(lst);

    lst.goToFirst();
    while(lst.getCurrent(d))
    {
        append(d);
        lst.deleteCurrent();
        lst.goToFirst();
    }
}
