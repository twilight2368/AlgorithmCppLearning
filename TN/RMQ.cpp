#include <bits/stdc++.h>
using namespace std;
#define MAX 5000

int lookup[MAX][MAX];

struct Query
{
    int L, R;
};

void preprocess(int arr[], int n)
{

    for (int i = 0; i < n; i++)
        lookup[i][0] = i;

    for (int j = 1; (1 << j) <= n; j++)
    {

        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {

            if (arr[lookup[i][j - 1]] < arr[lookup[i + (1 << (j - 1))][j - 1]])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}

int query(int arr[], int L, int R)
{

    int j = (int)log2(R - L + 1);

    if (arr[lookup[L][j]] <= arr[lookup[R - (1 << j) + 1][j]])
        return arr[lookup[L][j]];

    else
        return arr[lookup[R - (1 << j) + 1][j]];
}

void RMQ(int arr[], int n, Query q[], int m)
{
    int sum = 0;
    preprocess(arr, n);

    for (int i = 0; i < m; i++)
    {

        int L = q[i].L, R = q[i].R;
        sum = sum + query(arr, L, R);
    }

    cout << sum << endl;
}

// Driver code
int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int num_q;

    cin >> num_q;

    Query query[num_q];
    int x, y;

    for (int i = 0; i < num_q; i++)
    {
        cin >> x >> y;
        query[i] = {x, y};
    }

    RMQ(arr, n, query, num_q);
    return 0;
}
