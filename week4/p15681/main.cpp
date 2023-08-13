#include <iostream>
#include <ios>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> subs;

int dfs(int curr, int prev) {
    visited[curr] = true;

    for(auto next : graph[curr]) {
        if (next == prev) continue;
        subs[curr] += dfs(next, curr);
    }

    return subs[curr];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n_nodes, root, n_queries;
    cin >> n_nodes >> root >> n_queries;
    cin.ignore();

    graph.resize(n_nodes+1);
    visited.resize(n_nodes+1, false);
    subs.resize(n_nodes+1, 1);
    int x, y;

    for (int i = 1; i != n_nodes; ++i) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        cin.ignore();
    }

    dfs(root, 0);

    int q;

    for (int i = 0; i != n_queries; ++i) {
        cin >> q;
        cin.ignore();
        cout << subs[q] << '\n';
    }

    cout << endl;
    return 0;
}

