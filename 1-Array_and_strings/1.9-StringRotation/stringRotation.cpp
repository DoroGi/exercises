#include <iostream>
#include <string>

using namespace std;

//O(A+B)
bool isSubstring(string str, string substr)
{
    return str.find(substr) != string::npos;
}

//O(A+B)
bool stringRotation(string s1, string s2)
{
    if (s1.size() != s2.size()) return false;
    return isSubstring(s1+s1, s2);
}

int main()
{
    string w1, w2;
    cout << "Insert word 1" << endl;
    cin >> w1;
    cout << "Insert word 2" << endl;
    cin >> w2;
    string result = stringRotation(w1, w2) ? "yes" : "no";
    cout << result << endl;
    return 0;
}