#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

int modularNum(){
    long long a = 10;
    for (int i = 1; i < 10; i++)
    {
        a = a*a;
    }
    
    return a + 7;
}

int z = modularNum();

int exponentMod(long long x, long long y)
{
    
}

int main(){
    long long x, y;
    cin >> x >> y;

    cout << exponentMod(x, y);
    

}