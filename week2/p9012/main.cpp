#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines([](istream& in){
        size_t n;
        in >> n;
        in.ignore();
        return n;
    }(cin));

    for (auto& line : lines)
        getline(cin, line);

    stack<char> st;

    for (const auto& line : lines) {

        for (char c : line) {

            if (c == '(') {
                st.push(c);
            }
            else {

                if (st.empty()) {
                    st.push(c);
                    break;
                }
                else {
                    st.pop();
                }

            }

        }

        cout << (st.empty() ? "YES" : "NO") << '\n';
        while (!st.empty()) st.pop();
    }

    cout << endl;
    return 0;
}
