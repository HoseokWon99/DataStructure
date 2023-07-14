#include <iostream>
#include <ios>
#include <list>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    list<int> people;

    for (int i = 1; i <= n; ++i)
        people.push_back(i);

    auto advance = [&people, &k](list<int>::iterator& it) {
        for (int i = 0; i != k-1; ++i) {
            ++it;
            if (it == people.end()) it = people.begin();
        }
    };

    auto erase = [&people](list<int>::iterator& it) {
        auto ret = people.erase(it);
        return ret != people.end() ? ret : people.begin();
    };

    auto curr = people.begin();
    vector<int> permutation;
    permutation.reserve(n);

    while (!people.empty()) {
        advance(curr);
        permutation.push_back(*curr);
        curr = erase(curr);
    }

    cout << '<' << permutation.front();

    for (auto it = permutation.begin() + 1; it != permutation.end(); ++it) {
        cout << ", " << *it;
    }

    cout << '>' << endl;
    return 0;
}