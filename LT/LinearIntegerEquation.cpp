#include <iostream>

using namespace std;
int result[10];

void printResult(int n)
{
    for (int i = 0; i < n-1; i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;
}

void solvingProblem(int n, int m, int layer, int sum)
{
    if (layer == n-1 && sum == m)
    {
        printResult(n);
        sum = sum - result[layer];
        return;
    }
    else if (layer == n - 1)
    {
        sum = sum - result[layer];
        return;
    }

    for (int i = 1; i < m; i++)
    {
        result[layer] = i;
        sum = sum + result[layer];
        solvingProblem(n, m, layer + 1, sum);
        sum = sum - result[layer];
    }
}

int main()
{
    // 2 <= n <= 10
    // 1 <= M <= 20

    int n, m;
    cin >> n >> m;
    solvingProblem(n+1, m, 0, 0);

    return 0;
}