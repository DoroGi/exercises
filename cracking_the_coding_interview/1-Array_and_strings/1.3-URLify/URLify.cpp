#include <iostream>
#include <string>

using namespace std;

//Signature comes from exercise O(n)
void URLify (char input[], size_t trueLength)
{
    size_t totalLength = strlen(input);
    size_t i = trueLength-1;
    for (size_t j=totalLength-1; j>0; j--)
    {
        if (input[i] == ' ')
        {
            input[j--] = '0';
            input[j--] = '2';
            input[j] = '%';
        }
        else
        {
            input[j]=input[i];
        }
        i--;
    }
};

int main() 
{
    char input[] = "the answer is 42      ";
    size_t trueLength = 16;
    URLify(input, trueLength);
    cout << input << endl;
    return 0;
}