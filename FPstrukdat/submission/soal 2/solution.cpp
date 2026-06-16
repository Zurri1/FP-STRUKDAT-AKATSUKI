// solution.cpp — THIS IS WHAT YOU WILL WORK ON.
//
// Write your algorithm ONLY inside the solve() function below.
// Do not add other functions. Do not modify harness.h.
//
// Compile: g++ -O2 -std=c++17 solution.cpp -o solution
// Run:     ./solution ../maps/soal1.txt output.txt
// View:    open engine/index.html, select the question/map, drag output.txt, click Play/Run.

#include "../submission/harness.h"
#include <queue>
#include <set>

vector<Cell> solve(vector<vector<char>>& grid, Cell start, Cell goal)
{
    vector<Cell> visited_order;

    queue<Cell> q;
    set<Cell> visited;

    q.push(start);
    visited.insert(start);

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty())
    {
        Cell current = q.front();
        q.pop();

        visited_order.push_back(current);

        if (current == goal)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nr = current.first + dr[i];
            int nc = current.second + dc[i];

            if (!inBounds(nr, nc))
                continue;

            if (isWall(grid[nr][nc]))
                continue;

            Cell neighbor = {nr, nc};

            if (visited.count(neighbor))
                continue;

            visited.insert(neighbor);

            came_from[neighbor] = current;

            q.push(neighbor);
        }
    }

    return visited_order;
}
