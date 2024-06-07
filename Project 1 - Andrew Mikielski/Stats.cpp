// Andrew Mikielski Project 1
Stats::Stats()
{
    counter = 0;
    current = 0;
}

void Stats::swap(int i1, int i2)
{
    double temp = nums[i1];
    nums[i1] = nums[i2];
    nums[i2] = temp;
}

// Insert Sort
void Stats::insert(int i)
{
    if(i < 1)
        return;
    if(nums[i] > nums[i-1])
        return;
    swap(i, (i-1));
    insert(i-1);
}

// Insert Sort
void Stats::sort()
{
    for(int i = 1; i < counter; i++)
        insert(i);
}

bool Stats::addNumber(double num)
{
    if(counter >= 1000)
        false;
    nums[counter++] = num;
    sort(); // Sorting data on every input to keep data usable for Statistics
    return true;
}

bool Stats::goToFirst()
{
    if(counter == 0)
        return false;
    current = 0;
    return true;
}

bool Stats::goToNext()
{
    if(current >= counter)
        return false;
    current++;
    return true;
}

bool Stats::getCurrent(double &num)
{
    if(current >= counter)
        return false;
    num = nums[current];
    return true;
}

// Assumes data sorted least to greatest
double Stats::minimum()
{
    if(counter == 0)
        return 0;
    return nums[0];
}

// Assumes data sorted least to greatest
double Stats::maximum()
{
    if(counter == 0)
        return 0;
    return nums[counter-1];
}

double Stats::sum()
{
    if(counter == 0)
        return  0;
    double sum = 0;
    for(int i = 0; i < counter; i++)
        sum += nums[i];
    return sum;
}

double Stats::mean()
{
    if(counter == 0)
        return 0;
    return (sum()/counter);
}

// Assumes data sorted least to greatest
double Stats::median()
{
    if(counter == 0)
        return 0;
    // If there's an even amount of numbers in array, Then calculate median with avg of the two numbers in the middle.
    if(counter%2 == 0)
        return ((nums[counter/2]+nums[(counter/2)-1])/2);
    return (nums[counter/2]);
}

bool Stats::deleteCurrent()
{
    if(current >= counter)
        return false;
    swap(current, (counter-1));
    counter--;
    return true;
}

bool Stats::search(double num)
{
    for(int i = 0; i < counter; i++)
    {
        if(num == nums[i])
        {
            current = i;
            return true;
        }
    }
    return false;
}

bool Stats::removeNumber(double num)
{
    if(counter == 0)
        return false;

    //if statement deletes FIRST INSTANCE of number
    if(search(num))
    {
        deleteCurrent();
        /* deleteCurrent() unsorts data
           must sort to keep data usable for Statistics */
        sort();
    }

    return true;
}

void Stats::clearList()
{
    counter = 0;
    current = 0;

    return;
}
