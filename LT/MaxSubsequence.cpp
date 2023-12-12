#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> table;
int maxDP = -100000;

int j;

void DynamicProgramMaxSS(int array[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            table[i][j] = table[i-1][j-1] + table[1][j];
            maxDP = max(maxDP, table[i][j]);
        }
        
    }
    
    
}

int main()
{

    int n;

    cin >> n;

    int array[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> array[i];
    }

    table.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        table[i].resize(n + 1);
    }

    for (int i = 1; i <= n; i++)
    {
        table[1][i] = array[i];
    }

   DynamicProgramMaxSS(array, n);

   cout << maxDP << endl;

    return 0;
}