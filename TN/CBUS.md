Description

There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, serving n passengers and coming back to point 0. 

Input

Line 1 contains n and k (1≤n≤11,1≤k≤10)  
Line i+1 (i=1,2,…,2n+1) contains the (i−1)th line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).

Output

Unique line contains the length of the shortest route.

Example

Input
```
3  2
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0
```

Output
```
25
```


```cpp  
#include<iostream>
using namespace std;

int road[100][100];
int way[100];
int minDistance = 10000;


void backTracking(int step, int k , int n, int load, int appear[],int distance) {
    if(step == 2*n+ 1) {
        distance += road[way[step-1]][0];
        if(distance < minDistance) minDistance = distance;
        distance -= road[way[step-1]][0];
        return;
    }

    for (int i = 1; i <=2*n;i++)
    {
        if(distance + 2*n-1 - step < minDistance) {
            if(i <= n && load < k && appear[i] == 0) {
                way[step] = i;
                appear[i] = 1;
                load += 1;
                distance += road[way[step-1]][way[step]];
                backTracking(step + 1, k,n,load,appear,distance);
                appear[i] = 0;
                load -= 1;
                distance -= road[way[step-1]][way[step]];
                
            } else if(i > n && load > 0 && appear[i] == 0 && appear[i-n] == 1) {
                way[step] = i;
                appear[i] = 1;
                load -= 1;
                distance += road[way[step-1]][way[step]];
                backTracking(step + 1, k,n,load,appear,distance);
                appear[i] = 0;
                load += 1;
                distance -= road[way[step-1]][way[step]];
            }
        }
    }
}




int main() {
    int n,k;
    cin >> n >> k;
    int length = 2*n +1;
    for(int i =0;i < length;i++) {
        for(int j = 0; j< length;j++) {
            cin >> road[i][j];
        }
    }

    int appear[2*n+1];
    for(int i =1;i<=2*n;i++) {
        appear[i] = 0;
    }
    way[0] = 0;
    backTracking(1,k,n,0,appear,0);
    cout << minDistance;
    return 0;
}
```
