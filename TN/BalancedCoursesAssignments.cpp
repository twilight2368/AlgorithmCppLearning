#include <iostream>
#include <climits>

using namespace std;

int conflict[31][31];
int teaching[11][31];
int total_load[11];
int subject[31];
int load_min = INT_MAX;

bool Check(int teacher, int t_class){
    if (teaching[teacher][t_class] == 1)
    {
       for (int i = 1; i < t_class; i++)
       {
            if (conflict[i][t_class] == 1 && subject[i] == teacher)
            {
                return false;
            }        
       }      
       return true;
    }   
    return false;
}

void Solution(int M)
{
    int max_load = 0;
    for (int i = 1; i <= M; i++)
    {
       max_load = max(max_load, total_load[i]);
    }
    // cout << max_load << endl;
    load_min = min(load_min, max_load);
}

void Try(int t_class, int N, int M){
    for (int i = 1; i <= M; i++)
    {
        if (Check(i, t_class))
        {
            subject[t_class] = i;
            total_load[i] = total_load[i] + 1;

            if (t_class == N)
            {
                Solution(M);
            }else
            {
                if (total_load[i] < load_min)
                {
                    Try(t_class + 1, N, M);
                }
                
            }

            total_load[i] = total_load[i] - 1;
          
        }
        
    }

    return;
    
}

int main(){

    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            conflict[i][j] = 0;
        }
        
    }

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            teaching[i][j] = 0;
        }
    }

    for (int i = 0; i < 11; i++)
    {
        total_load[i] = 0;
    }
    

    int m, n;
    cin >> m >> n;

    int t, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            cin >> v;
            teaching[i][v] = 1;
        }       
    }

    int k;
    int a, b;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        conflict[a][b] = 1;
        conflict[b][a] = 1;
    }
    
    Try(1, n, m);
    
    if (load_min == INT_MAX)
    {
        cout << -1 << endl;
    }else
    {
        cout << load_min << endl;
    }
    
    return 0;
}