#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

long modularNum(){
    return 1e9 + 7;
}

int exponentMod(long long x, long long y, long z)
{
    long num = 0;
    long a = 0;

    if (x == 0){
        return 0;
    }
    if (y == 0)
    {
        return 1;
    }

    if (y % 2 == 0)
    {
        a = exponentMod(x, y/2, z);
        num = (a*a) % z;
    }else{
        a = exponentMod(x, y - 1, z);
        num = (x % z * a) % z;
    }
    
    return (int) (num + z) % z;
}

int main(){
    long long x, y;
    cin >> x >> y;
    long z = modularNum();
    //x^y % (10^9 -7)
    cout << exponentMod(x, y, z) << endl;

}