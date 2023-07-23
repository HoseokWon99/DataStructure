#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;

    [](istream& in, vector<string>& v) {
        v.clear();
        string s;

        while (getline(in, s)) {
            if (s == ".") break;
            v.emplace_back(s);
        }

    }(cin, lines);

    stack<char> st;

    for (const auto& line : lines) {

        for (char c : line) {

            if (c == '(' || c == '[') {
                st.push(c);
            }
            else if (c == ')') {

                if (st.empty()) {
                    st.push(c);
                    break;
                }
                else {
                    if (st.top() == '(') st.pop();
                    else break;
                }

            }
            else if (c == ']') {

                if (st.empty()) {
                    st.push(c);
                    break;
                }
                else {
                    if (st.top() == '[') st.pop();
                    else break;
                }

            }

        }

        cout << (st.empty() ? "yes" : "no") << '\n';
        while (!st.empty()) st.pop();
    }

    cout << endl;
    return 0;
}