#include <iostream>
#include <ios>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v([](istream& in) {
        size_t n;
        in >> n;
        in.ignore();
        return n;
    }(cin));

   for (auto& x : v)
       cin >> x;

    vector<int> nges(v.size(), -1);
    stack<size_t> st;

    for (size_t i = 0; i != v.size(); ++i) {

        while (!st.empty() && v[st.top()] < v[i] ) {
            nges[st.top()] = v[i];
            st.pop();
        }

        st.push(i);
    }

    for (auto nge : nges)
        cout << nge << ' ';

    cout << endl;
    return 0;
}
