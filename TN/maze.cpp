#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

typedef pair<int,int> xx;

int dx[] = {0, 1, -1,  0};
int dy[] = {1, 0,  0, -1};

queue<xx> my_queue;

int solve(int r, int c){
   
    
}



int main()
{
    int n,m,r,c;
    string input;
    cin >> n >> m >> r >> c;
    
    vector<vector<int>> maze;
   
   for (int i = 0; i < n; i++)
   {
        for (int j = 0; j < m; j++)
        {
                int a;
                cin >> a;
                maze[i].push_back(a);
        }
   }
   
    
    return 0;
}