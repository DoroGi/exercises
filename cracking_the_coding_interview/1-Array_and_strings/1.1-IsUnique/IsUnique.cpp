#include <iostream>
#include <string>
#include <bitset>

using namespace std;

//I assume only letters
bool isUnique(string input)
{
    if (input.size() > 256) return false;
    bitset<256> map;
    for (char letter : input)
    {
        int hash = letter - 'a';
        if (map.test(hash)) return false;
        else map.set(hash);
    }
    return true;
}

int main() 
{
    cout << "Insert word" << endl;
    string input;
    cin >> input;
    string result = isUnique(input) ? "isogram" : "doubles";
    cout << result << endl;
    return 0;
}