#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> words([](istream& in){
        size_t n;
        in >> n;
        in.ignore();
        return n;
    }(cin));

    for (auto& word : words)
        getline(cin, word);

    stack<char> st;
    size_t tot = 0;

    for (const auto& word : words) {

        for (char c : word) {

            if (!st.empty()) {
                if (c == st.top()) st.pop();
                else st.push(c);
            }
            else {
                st.push(c);
            }

        }

        if (st.empty()) {
            ++tot;
        }
        else {
            while (!st.empty())
                st.pop();
        }

    }

    cout << tot << endl;
    return 0;
}
