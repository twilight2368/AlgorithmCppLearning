#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

vector<int> myarray;

bool checkReq(int n, int distance, int c){
   int i = 0;
   int j = i + 1;

   while (i < n)
   {
       while (j <= n && myarray[j] - myarray[i] < distance)
       {
          j++;
       }

    
       
       
   }
   
   
   
}

int solvingProblem(int n, int c){
    int leftBound = 0;
    int rightBound = myarray[0] - myarray[n - 1];
    int mid;
    
    while (leftBound <= rightBound)
    {
        mid = (rightBound - leftBound) / 2 + leftBound;
        if (checkReq(n, mid, c))
        {
            leftBound = mid + 1;
        }else
        {
            rightBound = mid - 1;
        }
        
        
    }
    
    return rightBound;

}

int main(){
    int T;
    int N, C;
    int x;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> C;

        for (int j = 0; j < N; j++)
        {
            cin >> x;
            myarray[j] = x;
        }
        
        
        
    }
    
}