#include <iostream>
#include <string>

using namespace std;

int solving(string line)
{
    int count = 0;

    for (int i = 0; i < line.length(); i++)
    {
        switch (line[i])
        {
        case 'a':
        case 'd':
        case 'g':
        case 'j':
        case 'm':
        case 'p':
        case 't':
        case 'w':
        case ' ':
            count = count + 1;
            break;
        case 'b':
        case 'e':
        case 'h':
        case 'k':
        case 'n':
        case 'q':
        case 'u':
        case 'x':
            count = count + 2;
            break;

        case 'c':
        case 'f':
        case 'i':
        case 'l':
        case 'o':
        case 'r':
        case 'v':
        case 'y':
            count = count + 3;
            break;

        case 's':
        case 'z':
            count = count + 4;
            break;

        default:
            break;
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    string input[n];
    string nothing;

    getline(cin, nothing);

    for (int i = 0; i < n; i++)
    {
        getline(cin, input[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Case #" << i + 1 << ": " << solving(input[i]) << endl;
    }
}