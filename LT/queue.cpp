#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

queue<int> myqueue;
vector<int> result;

void inputHandling()
{
    string input;
    string cmd;
    string data;
    while (getline(cin, input))
    {
        if (input == "#")
            break;
        stringstream ss(input);

        ss >> cmd;

        if (cmd == "PUSH")
        {
            ss >> data;
            myqueue.push(stoi(data));
        }
        else if (cmd == "POP")
        {
            if (!myqueue.empty())
            {
                result.push_back(myqueue.front());
                myqueue.pop();
            }
            else
            {
                result.push_back(-1);
            }
        }
    }
}

void resultHandling()
{
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] != -1)
        {
            cout << result[i] << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }
    }
}
int main()
{
    inputHandling();
    resultHandling();
    return 0;
}