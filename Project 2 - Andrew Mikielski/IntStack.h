//Andrew Mikielski Project 2

class IntStackNode
{
    public:
        int number;
        IntStackNode *pNext;
        IntStackNode();
};

class IntStack
{
    private:
        IntStackNode *pTop;
    public:
        IntStack();
        ~IntStack();
        void push(int i);
        bool pop(int &i);
        bool empty();
};

#include "IntStack.cpp"
