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


vector<Cell> solve(vector<vector<char>>& grid, Cell start, Cell goal){
  vector<Cell> visited;  // list of visited cells (ordered) — return this

  // ===================== WRITE YOUR ALGORITHM HERE =====================
int dr[] = {-1, 1, 0, 0};
int dc[] = { 0, 0,-1, 1};

queue<Cell> q;      // antrian FIFO — inti BFS
set<Cell> seen;     // lacak sel yang sudah masuk queue

q.push(start);
seen.insert(start);

while (!q.empty()) {
  Cell current = q.front();   // ambil dari depan (FIFO)
  q.pop();

  visited.push_back(current); // catat sebagai explored

  if (current == goal) break; // sel yg sudah diprosessudah sampai goal, selesai

  int r = current.first;
  int c = current.second;

  for (int k = 0; k < 4; k++) {
    int nr = r + dr[k];
    int nc = c + dc[k];

    if (!inBounds(nr, nc)) continue;      // di luar grid

    Cell neighbor = {nr, nc};
    if (seen.count(neighbor)) continue;   // skip kalau sudah pernah dimasukkan antrian

    seen.insert(neighbor);
    came_from[neighbor] = current;        // record parent 
    q.push(neighbor);                     // masuk antrian
  }
}
  // =========================================================================
  return visited;
}
