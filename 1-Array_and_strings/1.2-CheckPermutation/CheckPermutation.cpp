#include <iostream>
#include <string>

using namespace std;

//I assume only letters O(n)
bool checkPermutation(string w1, string w2)
{
    if (w1.size() != w2.size()) return false;
    int chars[256] = {0};
    for (char letter : w1)
    {
        int hash = letter - 'a';
        chars[hash]++;
    }
    for (char letter : w2)
    {
        int hash = letter - 'a';
        chars[hash]--;
        if (chars[hash] < 0) return false;
    }
    return true;
};

int main() 
{
    string w1, w2;
    cout << "Insert word 1" << endl;
    cin >> w1;
    cout << "Insert word 2" << endl;
    cin >> w2;
    string result = checkPermutation(w1, w2) ? "yes" : "no";
    cout << result << endl;
    return 0;
}