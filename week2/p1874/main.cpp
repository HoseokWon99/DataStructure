#include <iostream>
#include <ios>
#include <list>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();

    auto seq = std::move([&n](istream& in) {
        int a;
        list<int> ret;

        for (int i = 0; i != n; ++i) {
            in >> a;
            ret.push_back(a);
            in.ignore();
        }

        return ret;
    }(cin));

    stack<int> stack;
    vector<char> ops;

    auto curr = seq.begin();
    int cnt = 0;
    stack.push(0);

    while (curr != seq.end()) {

        if (stack.top() < *curr) {
            stack.push(++cnt);
            ops.push_back('+');
        }
        else if (stack.top() == *curr) {
            stack.pop();
            ops.push_back('-');
            ++curr;
        }
        else {
            break;
        }

    }

    if (curr == seq.end()) {
        for (char c: ops)
            cout << c << '\n';

        cout.flush();
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
