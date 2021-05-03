#include <iostream>
#include <vector>

using namespace std;

//O(nm)
void zeroMatrix(vector<vector<int>> input)
{
    size_t M = input.size();
    size_t N = input[0].size();
    
    //check if first row has zeros, as we will use it as support data structure O(n)
    bool firstRowHasZero = false;
    for (int i=0; i<N; i++) 
    {
        if (input[0][i]==0) firstRowHasZero = true;
    }

    //check if first column has zeros, as we will use it as support data structure O(m)
    bool firstColumnHasZero = false;
    for (int i=0; i<M; i++) 
    {
        if (input[i][0]==0) firstColumnHasZero = true;
    }

    //check is THE REST of the matrix has zeros O(nm)
    for (int i=1; i<M; i++)
    {
        for (int j=1; j<N; j++) 
        {
            if (input[i][j]==0)
            {
                input[i][0] = 0;
                input[0][j] = 0;
            }
        }
    }

    //Put zeros based on first row O(nm)
    for (int j=0; j<N; j++) 
    {
        if (input[0][j]==0)
            for (int i=1; i<M; i++)
                input[i][j] = 0;
    }

    //Put zeros based on first column O(nm)
    for (int i=0; i<M; i++) 
    {
        if (input[i][0]==0)
            for (int j=1; j<N; j++)
                input[i][j] = 0;
    }

    // Now zero the first row O(n)
    if (firstRowHasZero)
        for (int i=0; i<N; i++)
            input[0][i] = 0;

    // Now zero the first column O(m)
    if (firstColumnHasZero) 
        for (int i=0; i<M; i++)
            input[i][0] = 0;

    // write the result to console
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++) 
        {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> input = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 0, 12},
        {13, 14, 15, 16},
        {0, 18, 0, 20}
    };
    zeroMatrix(input);
    return 0;
}