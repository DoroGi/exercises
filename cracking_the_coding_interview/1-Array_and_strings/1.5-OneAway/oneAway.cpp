#include <iostream>
#include <string>

using namespace std;

//O(n)
bool checkRemoval(string longer, string shorter)
{
    size_t i1 = 0, i2 = 0;
    bool foundRemoved = false;
    while (i1 < longer.size())
    {
        if (longer[i1] != shorter[i2])
        {
            if (foundRemoved) return false;
            foundRemoved = true;
        }
        else
        {
            i2++;
        }
        i1++;
    }
    return true;
}

//O(n)
bool checkReplace(string first, string second)
{
    size_t i = 0;
    bool foundReplaced = false;
    while (i < first.size())
    {
        if (first[i] != second[i])
        {
            if (foundReplaced) return false;
            foundReplaced = true;
        }
        i++;
    }
    return foundReplaced;
}

//O(n)
bool oneAway(string first, string second)
{
    size_t firstSize = first.size();
    size_t secondSize = second.size();
    if (firstSize == secondSize)
        return checkReplace(first, second);
    else if (firstSize - secondSize == 1)
        return checkRemoval(first, second);
    else if (secondSize - firstSize == 1)
        return checkRemoval(second, first);
    else
        return false;
}

int main()
{
    string w1, w2;
    cout << "Insert word 1" << endl;
    cin >> w1;
    cout << "Insert word 2" << endl;
    cin >> w2;
    string result = oneAway(w1, w2) ? "yes" : "no";
    cout << result << endl;
    return 0;
}