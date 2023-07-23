#include <iostream>
#include <ios>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> buildings([](istream& in) {
        size_t n;
        in >> n;
        in.ignore();
        return n;
    }(cin));

    for (auto& h : buildings) {
        cin >> h;
        cin.ignore();
    }

    stack<int> stack;
    size_t tot = 0;

    for (auto h : buildings) {
        while (!stack.empty() && stack.top() <= h)
            stack.pop();

        tot += stack.size();
        stack.push(h);
    }

    cout << tot << endl;
    return 0;
}