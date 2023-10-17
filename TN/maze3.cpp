#include <iostream>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> my_queue;

int rowMov[] = {-1, 0, 0, 1};
int colMov[] = {0, -1, 1, 0};

bool isValid(int row, int col, int ROW, int COL)
{
    // return true if row number and column number is in range
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

int findThePath(vector<vector<int>> maze, vector<vector<bool>> visited, pair<int, int> src, int n, int m, int dest)
{
    int dist = 0;
    int num_on_q = 0;
    int add = 0;

    visited[src.first][src.second] = true;

    my_queue.push(src);
    num_on_q = num_on_q + 1;

    while (!my_queue.empty())
    {
        pair<int, int> current = my_queue.front();

        //cout << "Current dept: " << current.first << endl;

        if (current.first == dest - 1)
        {
            // If we have reached the destination
            dist = dist + 1; //Because we haven't added the last move to the destination
            return dist;
        }

        my_queue.pop();
        num_on_q = num_on_q - 1;

        for (int i = 0; i < 4; i++)
        {
            int row = current.first + rowMov[i];
            int col = current.second + colMov[i];

            if (isValid(row, col, n, m) && maze[row][col] == 0 && !visited[row][col])
            {
                // Add newest to the queue and visted
                visited[row][col] = true;
                my_queue.push({row, col});
                add = add + 1;
            }
        }
        
        if (num_on_q == 0)
        {
            // If old nodes all removed add newest ones and add distance + 1
            dist = dist + 1;
            num_on_q = num_on_q + add;
            add = 0;
        }    
    }

    return -1;
}

int main()
{
    int n, m, r, c;

    cin >> n >> m >> r >> c;

    vector<vector<int>> maze;

    maze.resize(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            maze[i].push_back(a);
        }
    }

    vector<vector<bool>> visited;
    visited.resize(n, vector<bool>(m, false));

    pair<int, int> src;
    src = make_pair(r - 1, c - 1);

    int dist = findThePath(maze, visited, src, n, m, n);

    if (dist != -1)
        cout << dist << endl;
    else
        cout << -1;

    return 0;
}