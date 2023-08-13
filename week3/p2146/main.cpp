#include <iostream>
#include <ios>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;

    for (int i = 1; i <= n; ++i)
        q.push(i);

    int x;

    while (true) {
        if (q.size() > 1) q.pop();

        x = q.front();
        q.pop();

        if (q.empty()) break;

        q.push(x);
    }

    cout << x << endl;
    return 0;
}
