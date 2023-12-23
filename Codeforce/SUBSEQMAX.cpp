#include <iostream>

using namespace std;

int n;
int S[107];

void solving(int n)
{
    int u, v;

    int max = S[1];
    int lastMax = S[1];

    for (int i = 2; i <= n; i++)
    {
        u = S[i];
        v = S[i] + lastMax;

        if (u > v)
        {
            lastMax = u; // Last max not change
        }
        else
        {
            lastMax = v; // update new last max value
        }

        if (lastMax > max)
        {
            max = lastMax;
        }
    }

    cout << max << endl;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> S[i];
    }

    solving(n);

    return 0;
}