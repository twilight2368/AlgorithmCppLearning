#include <iostream>
#include <climits>

using namespace std;

int minDist = INT_MAX;

int mapBus[25][25];

void Cbus(int n, int k, int load, int curr, int step, int dist, int visited[]){
    if (step == 2*n)
    {
        dist = dist + mapBus[curr][0];
        minDist = min(dist, minDist);
        return;
    }

    if (dist > minDist)
    {
        return;
    }
    
    for (int i = 1; i <= 2*n; i++)
    {       
        if (visited[i] == 0)
        {
            if (load < k && i <= n)
            {
                visited[i] = 1;
                Cbus(n, k, load + 1, i, step + 1, dist + mapBus[curr][i], visited);
                visited[i] = 0;
            }else if (i > n && visited[i-n] == 1)
            {
                visited[i] = 1;
                Cbus(n, k, load - 1, i, step + 1, dist + mapBus[curr][i], visited);
                visited[i] = 0;
            }                   
        }         
    }   
}

int main(){

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            mapBus[i][j] = 0;
        }
    }
    
    int n, k;
    cin >> n >> k;

    int n_n = 2*n;
    
    int visited[2*n+1];

    for (int i = 0; i <= n_n; i++)
    {
        visited[i] = 0;
    }
    
    
    for (int i = 0; i < n_n + 1; i++)
    {
        for (int j = 0; j < n_n + 1; j++)
        {
            cin >> mapBus[i][j];
        }
        
    }
    

    Cbus(n, k, 0, 0, 0, 0, visited);

    if (minDist != INT_MAX)
    {
       cout << minDist << endl;
    }else
    {
        cout << -1 << endl;
    }
      
    return 0;
}