// solution.cpp — THIS IS WHAT YOU WILL WORK ON.
//
// Write your algorithm ONLY inside the solve() function below.
// Do not add other functions. Do not modify harness.h.
//
// Compile: g++ -O2 -std=c++17 solution.cpp -o solution
// Run:     ./solution ../maps/soal1.txt output.txt
// View:    open engine/index.html, select the question/map, drag output.txt, click Play/Run.

#include "harness.h"
// Tambahkan include yang kalian butuhkan, contoh:
#include <queue>
#include <set>
#include <map>

vector<Cell> solve(vector<vector<char>>& grid, Cell start, Cell goal){
  vector<Cell> visited;  // list of visited cells (ordered) — return this

  // ===================== WRITE YOUR ALGORITHM HERE =====================

priority_queue<
        pair<int, Cell>,
        vector<pair<int, Cell>>,
        greater<pair<int, Cell>>
    > pq;

    map<Cell, int> dist;

    dist[start] = 0;
    pq.push({0, start});

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int cost = top.first;
        Cell current = top.second;

        if (cost > dist[current])
            continue;

        visited.push_back(current);

        if (current == goal)
            break;

        int r = current.first;
        int c = current.second;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (!inBounds(nr, nc))
                continue;

            if (isWall(grid[nr][nc]))
                continue;

            Cell neighbor = {nr, nc};

            int newCost = cost + cellCost(grid[nr][nc]);

            if (!dist.count(neighbor) || newCost < dist[neighbor])
            {
                dist[neighbor] = newCost;
                came_from[neighbor] = current;
                pq.push({newCost, neighbor});
            }
        }
    }

    return visited;
}