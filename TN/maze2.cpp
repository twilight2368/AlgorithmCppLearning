#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

// Check if it is possible to go to (x, y) from the current position. The
// function returns false if the cell has value 0 or already visited
bool isSafe(vector<vector<int>> &maze, vector<vector<bool>> &visited, int x, int y)
{
    return (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size()) &&
           maze[x][y] == 0 && !visited[x][y];
}

void findShortestPath(vector<vector<int>> &maze, vector<vector<bool>> &visited, int i, int j, int x, int y, int &min_dist, int dist)
{
    if (i == x && j == y)
    {
        min_dist = min(dist, min_dist);
        return;
    }
    // set (i, j) cell as visited
    visited[i][j] = true;
    // go to the bottom cell
    if (isSafe(maze, visited, i + 1, j))
    {
        findShortestPath(maze, visited, i + 1, j, x, y, min_dist, dist + 1);
    }
    // go to the right cell
    if (isSafe(maze, visited, i, j + 1))
    {
        findShortestPath(maze, visited, i, j + 1, x, y, min_dist, dist + 1);
    }
    // go to the top cell
    if (isSafe(maze, visited, i - 1, j))
    {
        findShortestPath(maze, visited, i - 1, j, x, y, min_dist, dist + 1);
    }
    // go to the left cell
    if (isSafe(maze, visited, i, j - 1))
    {
        findShortestPath(maze, visited, i, j - 1, x, y, min_dist, dist + 1);
    }
    // backtrack: remove (i, j) from the visited mazerix
    visited[i][j] = false;
}

// Wrapper over findShortestPath() function
int findShortestPathLength(vector<vector<int>> &maze, pair<int, int> &src, pair<int, int> &dest)
{
    if (maze.size() == 0 || maze[src.first][src.second] == 1 || maze[dest.first][dest.second] == 1)
    {
        //cout << "return here 0";
        return -1;
    }
    int row = maze.size();
    int col = maze[0].size();
    // construct an `M × N` mazerix to keep track of visited cells
    vector<vector<bool>> visited;
    visited.resize(row, vector<bool>(col));

    int dist = INT_MAX;
    findShortestPath(maze, visited, src.first, src.second, dest.first, dest.second, dist, 0);

    if (dist != INT_MAX)
    {
        return dist;
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
        //maze[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            maze[i].push_back(a);
        }
    }

    pair<int, int> src = make_pair(r - 1, c - 1);

    int dist;
    int crr_dist = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        if (maze[n - 1][i] != 1)
        {
            pair<int, int> dest = make_pair(n-1, i);
            dist = findShortestPathLength(maze, src, dest);

            if (dist != -1)
            {
                crr_dist = min(crr_dist, dist);                
            }
                    
        }
    }

    if (crr_dist != INT_MAX)
    {
        cout << crr_dist;
    }else
    {
        cout << -1;
    }
    return 0;
}
