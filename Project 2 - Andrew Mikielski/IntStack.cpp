//Andrew Mikielski Project 2

IntStackNode::IntStackNode()
{
    pNext = NULL;
}

IntStack::IntStack()
{
    pTop = NULL;
}

IntStack::~IntStack()
{
    int i;
    while(pop(i));
}

void IntStack::push(int i)
{
    IntStackNode *pNewNode = new IntStackNode();
    pNewNode->number = i;
    pNewNode->pNext = pTop;
    pTop = pNewNode;
}

bool IntStack::pop(int &i)
{
    if(pTop == NULL)
        return false;
    IntStackNode *pDelNode = pTop;
    i = pTop->number;
    pTop = pTop->pNext;
    delete pDelNode;
    return true;
}

bool IntStack::empty()
{
    return pTop == NULL;
}
