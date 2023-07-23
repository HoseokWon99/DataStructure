#include <iostream>
#include <ios>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n_lines;
    cin >> n_lines;
    cin.ignore();

    stack<int> stack;
    int x;

    for (int i = 0; i != n_lines; ++i) {
        cin >> x;

        if (x) stack.push(x);
        else stack.pop();

        cin.ignore();
    }

    int sum = 0;

    while (!stack.empty()) {
        sum += stack.top();
        stack.pop();
    }

    cout << sum << endl;
    return 0;
}
