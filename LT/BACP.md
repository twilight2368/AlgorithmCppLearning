# Description  

The BACP is to design a balanced academic curriculum by assigning periods to courses in a way that the academic load of each period is balanced. There are N courses 1, 2, …, N that must be assigned to M periods 1, 2, …, M. Each course i has credit ci and has some courses as prerequisites. The load of a period is defined to be the sum of credits of courses assigned to that period.

The prerequisites information is represented by a matrix ANxN in which Ai,j = 1 indicates that course i must be assigned to a period before the period to which the course j is assigned. Compute the solution satisfying constraints: 

Satisfy the prerequisites constraints:
- if Ai,j = 1, then course i must be assigned to a period before the period to which the course j is assigned
- The maximum load for all periods is minimal


## Input
Line 1 contains N and M (2 ≤ N ≤16, 2 ≤ M ≤ 5)
Line 2 contains c1, c2, …, cN
Line i+2 (i = 1,…, N) contains the ith line of the matrix A

## Output
Unique line contains that maximum load for all periods of the solution
found
## Example
### Input
```
6 2
4 4 4 4 2 4 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 1 0 0 0 
0 0 1 0 0 0 
1 0 0 0 0 0
```
### Output
```
12
```

# Example
```cpp

#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<=b; i++)
#define N 17
#define M 6

using namespace std;

int n,m;
int load[M];
int loadMin = INT_MAX;
int c[N], x[N];
int a[N][N];

bool Check(int v, int k)
{
	loop(i, 1, k-1)
	{
		if(a[i][k])
		{
			if(x[i]>=v) return false;
		}else if(a[k][i])
		{
			if(v>=x[i]) return false;
		}
	}
	return true;
}

int MAX(int* a, int* b)
{
	int j=0;
	for(int* i=a; i<=b; i++)
		if(*i>j) j=*i;
	return j;
}

void Solution()
{
	int maxLoad = MAX(&load[1], &load[m]);
	if(maxLoad < loadMin) loadMin = maxLoad;
}

void Try(int k)
{
	loop(v, 1, m)
	{
		if(Check(v, k))
		{
			x[k]=v;
			load[v]+=c[k];
			if(k==n) Solution();
			else{
				if(load[v]<loadMin) Try(k+1);
			}
			load[v]-=c[k];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	loop(i, 1, n)
		scanf("%d", c+i);
	loop(i, 1, n)
	{
		loop(j, 1, n)
		{
			scanf("%d", &a[i][j]);
		}
	}
	Try(1);
	printf("%d",loadMin);
	return 0;
}

```