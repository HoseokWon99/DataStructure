#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

class TreeCounter {

public:
    static constexpr int MAX_NODES = 501;

    TreeCounter() : _n_nodes{ 0 }, _visited{} {}

    void addEdge(int x, int y) {
        _graph[x].push_back(y);
        _graph[y].push_back(x);
    }

    void reset(int n_nodes) {
        _n_nodes = n_nodes;
        for_each_n(_graph, n_nodes + 1, [](vector<int>& v) { v.clear(); });
        fill_n(_visited, n_nodes + 1, false);
    }

    int count() {
        int ret = 0;

        for (int i = 1; i <= _n_nodes; ++i)
            if (dfs(i, 0)) ++ret;

        return ret;
    }

private:
    int _n_nodes;
    vector<int> _graph[MAX_NODES];
    bool _visited[MAX_NODES]{};

    bool dfs(int curr, int prev) {
        _visited[curr] = true;

        return all_of(_graph[curr].begin(), _graph[curr].end(), [this, &curr, &prev](int next) {
            if (next == prev) return true;
            return !_visited[next] && this->dfs(next, curr);
        });
    }
};

ostream& PrintCase(ostream& os, int case_n, int n_trees) {
    os << "Case " << case_n << ": ";

    if (n_trees == 0)
        os << "No trees.";
    else if (n_trees == 1)
        os << "There is one tree.";
    else
        os << "A forest of " << n_trees << " trees.";

    return os;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, x, y;
    TreeCounter counter;
    int case_n = 1;

    while (true) {
        cin >> V >> E;
        if (!V && !E) break;
        cin.ignore();

        counter.reset(V);

        for (int i = 0; i != E; ++i) {
            cin >> x >> y;
            counter.addEdge(x, y);
            cin.ignore();
        }

        PrintCase(cout, case_n++, counter.count()) << '\n';
    }

    cout << endl;
    return 0;
}

