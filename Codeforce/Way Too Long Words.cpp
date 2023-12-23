#include <iostream>

using namespace std;

int main()
{

    int n;

    cin >> n;
    string input[n];
    string a;

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    for (int i = 0; i < n; i++)
    {
        a = input[i];
        if (a.length() <= 10)
        {
            cout << a << endl;
        }
        else
        {
            cout << a[0] << a.length() - 2 << a[a.length() - 1] << endl;
        }
    }
}