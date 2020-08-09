#include <iostream>

using namespace std;

//O(n^2)
void rotateMatrix(int input[][4])
{
    //O(n)
    size_t N = sizeof(input[0])/sizeof(input[0][0]);
    
    //O(n^2)
    for (int layer=0; layer<N/2; layer++)
    {
        int end = N - 1 - layer;
        for (int i=layer; i<end; i++)
        {
            int tmp = input[layer][i]; //save elm on top line
            input[layer][i] = input[N-1-i][layer]; //move left line to top line
            input[N-1-i][layer] = input[N-1-layer][N-1-i]; //move bottom line to left line
            input[N-1-layer][N-1-i] = input[i][N-1-layer]; //move right line to bottom
            input[i][N-1-layer] = tmp; //put saved elm to right line
        }
    }

    for (int i=0; i<N; i++)
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
    int input[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    rotateMatrix(input);

    return 0;
}