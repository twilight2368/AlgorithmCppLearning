#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int credit[20];
int required[20][20];
int curriculum[20];
int total_load[10]; 
int load_min = INT_MAX;

bool Check(int semester, int subject){
    for (int i = 1; i < subject; i++)
    {
        if (required[i][subject])
        {
            if (curriculum[i] >= semester)
            {
                return false;
            }
            
        }else if (required[subject][i])
        {
            if (curriculum[i] <= semester)
            {
                return false;
            }
        }
    }   
    return true;
}

void Solution(int M){
    int max_load = 0;
    for (int i = 1; i <= M; i++)
    {
        max_load = max(max_load, total_load[i]);
    }
    //cout << max_load << endl;
    load_min = min(load_min, max_load);
}


void Try(int subject, int M, int N){
    for (int i = 1; i <= M; i++)
    {
        if (Check(i, subject))
        {
            curriculum[subject] = i;
            total_load[i] = total_load[i] + credit[subject];

            if (subject == N)
            {
                Solution(M);     
            }else
            {
                if (total_load[i] < load_min)
                    Try(subject + 1, M, N);
            }

            total_load[i] = total_load[i] - credit[subject];         
        }
        
    }   
}



int main()
{
    for (int i = 0; i < 10; i++)
    {
        total_load[i] = 0;
    }

    for (int i = 0; i < 20; i++)
    {
        curriculum[i] = 0;
    }
    

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> credit[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> required[i][j];
        }
    }

    Try(1, M, N);

    cout << load_min << endl;
}


