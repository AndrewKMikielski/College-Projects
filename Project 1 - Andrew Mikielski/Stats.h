// Andrew Mikielski Project 1
class Stats
{
private:
    double nums[1000];
    int counter, current;

    void swap(int i1, int i2);
    void insert(int i);

public:
    Stats();
    void sort();
    double minimum();
    double maximum();
    double sum();
    double mean();
    double median();

    bool goToFirst();
    bool goToNext();
    bool getCurrent(double &num);
    bool deleteCurrent();
    bool search(double num);
    bool addNumber(double num);
    bool removeNumber(double num);
    void clearList();
};

#include "Stats.cpp"
