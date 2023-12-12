#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> int_a, int_b, result;

int main(){
    string a, b;
    string c;
    cin >> a >> b;

    int mem = 0;
    int add = 0;

    
    if (a.length() >= b.length())
    {
        int_a.resize(a.length());
        int_b.resize(a.length());
    }
    else
    {
        int_a.resize(b.length());
        int_b.resize(b.length());
    }
    
    for (int i = 0; i < a.length(); i++)
    {
        c = a[i];
        int_a[a.length() - 1 - i] = stoi(c);
    }

    for (int i = 0; i < b.length(); i++)
    {
        c = b[i];
        int_b[b.length() - 1 - i] = stoi(c);
    }

   for (int i = 0; i < int_a.size(); i++)
   {
      add = int_a[i] + int_b[i] + mem;
      mem = add/10;
      result.push_back(add%10);
   }

   if (mem > 0)
   {
     result.push_back(mem);
   }
   

   for (int i = result.size() - 1; i >= 0; i--)
   {
     cout << result[i];
   }
   cout << endl;
   
   
}