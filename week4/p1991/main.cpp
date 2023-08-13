#include <iostream>
#include <ios>
#include <unordered_map>
#include <utility>

using namespace std;

using Tree = unordered_map<char, pair<char, char>>;

void PreOrder(Tree& tree, char curr) {
    if (curr == '.') return;
    auto& children = tree[curr];
    cout << curr;
    PreOrder(tree, children.first);
    PreOrder(tree, children.second);
}

void InOrder(Tree& tree, char curr) {
    if (curr == '.') return;
    auto& children = tree[curr];
    InOrder(tree, children.first);
    cout << curr;
    InOrder(tree, children.second);
}

void PostOrder(Tree& tree, char curr) {
    if (curr == '.') return;
    auto& children = tree[curr];
    PostOrder(tree, children.first);
    PostOrder(tree, children.second);
    cout << curr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n_nodes;
    cin >> n_nodes;
    cin.ignore();

    Tree tree;
    tree.reserve(n_nodes);

    char x, y, z;

    for (int i = 0; i != n_nodes; ++i) {
        cin >> x >> y >> z;
        tree.emplace(x, make_pair(y, z));
        cin.ignore();
    }

    PreOrder(tree, 'A');
    cout << '\n';
    InOrder(tree, 'A');
    cout << '\n';
    PostOrder(tree, 'A');
    cout << endl;

    return 0;
}
