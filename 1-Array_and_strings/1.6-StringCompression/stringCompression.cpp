#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// I assume only lowercase letter O(n)
string stringCompression(string input)
{
    stringstream ss;
    char lastLetter = NULL;
    int occurrences = 0;
    for (size_t i = 0; i <= input.size(); i++)
    {
        char currentLetter = input[i];
        if (currentLetter != lastLetter)
        {
            if (occurrences > 0)
            {
                ss << lastLetter;
                ss << occurrences;
            }
            lastLetter = currentLetter;
            occurrences = 1;
        }
        else
        {
            occurrences++;
        }
    }
    string result = ss.str();
    return input.size() <= result.size() ? input : result;
}

int main() {
    string input;
    cout << "Insert string to compress" << endl;
    cin >> input;
    string result = stringCompression(input);
    cout << result << endl;
    return 0;
}