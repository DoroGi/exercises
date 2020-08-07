#include <iostream>
#include <string>

using namespace std;

//O(n)
bool palindromePermutation(string input)
{
    int chars[60] = {0};
    for(char letter : input)
    {
        int hash = letter - 'a';
        chars[hash]++;
    }
    bool foundOdd = false;
    for(int letter : chars)
    {
        if (letter > 0 && letter % 2 != 0)
        {
            if (foundOdd) return false;
            else foundOdd = true;
        }
    }
    return true;
}

int main()
{
    string input;
    cout << "Insert a word" << endl;
    cin >> input;
    string result = palindromePermutation(input) ? "yes" : "no";
    cout << result << endl;
    return 0;
}