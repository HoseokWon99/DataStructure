#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> graph;
vector<bool> visited;
vector<int> parent;
int last;

int FindLast();
void PseudoInOrder(int curr, int&);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n_nodes;
    cin >> n_nodes;
    cin.ignore();

    graph.resize(n_nodes+1);
    visited.resize(n_nodes+1, false);
    parent.resize(n_nodes+1, 0);
    int x, y, z;

    for (int i = 0; i != n_nodes; ++i) {
        cin >> x >> y >> z;
        graph[x] = std::move(make_pair(y, z));
        cin.ignore();
    }

    last = FindLast();

    int cnt = 0;
    PseudoInOrder(1, cnt);
    cout << cnt << endl;

    return 0;
}

int FindLast() {
    auto curr = graph.begin() +1;

    while (curr->second != -1)
        curr = graph.begin() + (curr->second);

    return static_cast<int>(curr - graph.begin());
}

void PseudoInOrder(int curr, int& cnt) {
    visited[curr] = true;
    int left = graph[curr].first;
    int right = graph[curr].second;

    if (left != -1 && !visited[left]) {
        parent[left] = curr;
        PseudoInOrder(left, ++cnt);
    }
    else if (right != -1 && !visited[right]) {
        parent[right] = curr;
        PseudoInOrder(right, ++cnt);
    }
    else if (curr == last) {
        return;
    }
    else if (parent[curr]) {
        PseudoInOrder(parent[curr], ++cnt);
    }
}