#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    const int MAX_NODES = 1000001;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> graph[MAX_NODES] {};
    bool visited[MAX_NODES];

    int n_nodes;
    cin >> n_nodes;
    cin.ignore();

    int x, y;

    for (int i = 0; i != n_nodes; ++i) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        cin.ignore();
    }

    fill_n(visited + 1, n_nodes + 1, false);
    stack<int> st;
    vector<int> res(n_nodes+1);

    visited[1] = true;
    st.push(1);

    int u, v;

    while (!st.empty()) {
        u = st.top();

        if (!graph[u].empty()) {
            v = graph[u].back();

            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
                res[v] = u;
            }

            graph[u].pop_back();
        }
        else {
            st.pop();
        }
    }

    for (auto it = res.begin() + 2; it != res.end(); ++it)
        cout << *it << '\n';

    cout << endl;
    return 0;
}