# Problem: Week3 - Linear Integer Equation - coefficent 1

## Description

Given two integer n and M. Write a program that generates all ordered collection (X1, X2, ..., Xn) such that: X1 + X2 + . . . + Xn = M

Input
Line 1: contains 2 integers n and M (2 <= n <= 10, 1 <= M <= 20)
Output
Write in each line X1, X2, ..., Xn separated by a SPACE character

Example

Input  
```3  5```  
Output  

```
1 1 3
1 2 2
1 3 1
2 1 2
2 2 1
3 1 1
```

```cpp
#include<iostream>
using namespace std;
int array[100];

void printSolution(int n) {
 for(int i =0;i < n ;i ++) {
  cout << array[n] << ' ';
 }
 cout << endl;
}

void genPermutation(int k,int n , int m, int sum) {
 if(k == n-1 && sum == m) {
  printSolution(n);
  sum -= array[k];
  return;
 }
 else if(k == n-1) {
  sum -= array[k]; 
  return; 
 }
 for(int i = 1;i<=m;i++) {
  array[k] = i;
  sum += array[k];
  genPermutation(k+1,n,m,sum);
  sum -= array[k];
 }
}

int main(){
 int n,m;
 cin >> n >> m;
 genPermutation(0,n,m,0);
 return 0;
}
```
