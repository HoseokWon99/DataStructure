#include <iostream>
#include <ios>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAX_NODES = 1001;
constexpr int MAX_PAIRS = 1001;

vector<pair<int, int>> graph[MAX_NODES];
bool visited[MAX_NODES];

int dist(int, int);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_nodes, n_pairs;
    cin >> n_nodes >> n_pairs;
    cin.ignore();

    int u, v, w;

    for (int i = 1; i != n_nodes; ++i) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
        cin.ignore();
    }

    int from, to;

    for (int i = 0; i != n_pairs; ++i) {
        cin >> from >> to;
        cin.ignore();
        fill_n(visited, n_nodes+1, false);
        cout << dist(from, to) << '\n';
    }

    cout << endl;
    return 0;
}

int dist(int from, int to) {
    int d = 0;
    queue<pair<int, int>> q;

    visited[from] = true;
    q.emplace(from, 0);
    int curr, weight;

    while (!q.empty()) {
        curr = q.front().first;
        weight = q.front().second;

        q.pop();
        visited[curr] = true;

        if (curr == to) {
            d = weight;
            break;
        }

        for (auto& p : graph[curr]) {
            if (visited[p.first]) continue;
            q.emplace(p.first, p.second + weight);
        }
    }

    return d;
}