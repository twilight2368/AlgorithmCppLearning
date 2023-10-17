#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>

using namespace std;

int mymap[20][20];
int f_sum = INT_MAX;

void travelingSalesManProblem(int crr, int sum, int total, int dist, bool visited[]){

    if (dist == total - 1)
    {
        sum = sum + mymap[crr][0];
        f_sum = min(f_sum, sum);
        return;
    }

    if (sum > f_sum)
    {
        return;
    }
    
    for (int i = 1; i < total; i++)
    {
        if (!visited[i] && mymap[crr][i] > 0)
        {
            visited[i] = true;
            travelingSalesManProblem(i , sum + mymap[crr][i], total, dist + 1, visited);
            visited[i] = false;
        }
    }
    return;
}

int main()
{
    int n;

    cin >> n;

    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[n] = false;
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mymap[i][j];
        }
    }

    travelingSalesManProblem(0,0,n,0, visited);

    cout << f_sum << endl;

 
}