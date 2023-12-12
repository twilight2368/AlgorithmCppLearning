#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>

using namespace std;


vector<pair<int,int>> my_vec;

int condition(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

void solve(int n){
    int result = 0;   // result
    int last = -1; // the end point of last chosen segment
    sort(my_vec.begin(), my_vec.end(), condition);

    for (int i = 0; i < n; i++)
        if (my_vec[i].first > last)
        { 
            result++;
            last = my_vec[i].second;
        }
    
    cout << result << endl;
}

int main(){
 int n;
 cin >> n;
 int a,b;
 for (int i = 0; i < n; i++)
 {
    cin >> a >> b;
    my_vec.push_back(make_pair(a, b));
 }

 solve(n);
 
}