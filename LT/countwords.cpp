#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>


using namespace std;

//vector<string> mylist;
map<string, int> mymap;

int main()
{
    string hello;
    string hi;
    while (getline(cin, hello))
    {
        if (hello.length() == 0)
            break;
        stringstream ss(hello);
        while (ss >> hi)
        {
            if (hi.length() <= 20)
            {
                mymap[hi]++;
            }
            
        }
    }

    //sort(mylist.begin(), mylist.end());

    // for (int i = 0; i < mylist.size(); i++)
    // {
    //     cout << mylist[i] << " " << mymap[mylist[i]] << endl;
    // }

    for (auto i = mymap.begin(); i != mymap.end(); i++)
        cout << i->first << " " << i->second << endl;
}
