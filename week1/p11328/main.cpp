#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    cin.clear();

    vector<pair<string, string>> v(n);

    for (auto& pair : v) {
        cin >> pair.first >> pair.second;
        cin.clear();
    }

    for (auto& p : v) {
        sort(p.first.begin(), p.first.end());
        sort(p.second.begin(), p.second.end());
        bool is_possible = equal(p.first.begin(), p.first.end(), p.second.begin());
        cout << (is_possible ? "Possible\n" : "Impossible\n");
    }

    cout << endl;
    return 0;
}
