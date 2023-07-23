#include <iostream>
#include <ios>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v([](istream& in){
        size_t n;
        in >> n;
        in.ignore();
        return n;
    }(cin));

    for (auto& h : v) {
        cin >> h;
        cin.ignore();
    }

    stack<pair<int, size_t>> st;
    size_t n_pairs = 0;

    for (auto h : v) {
        pair<int, size_t> p(h, 1);

        while (!st.empty()) {

            if (st.top().first > h) {
                ++n_pairs;
                break;
            }
            else {
                n_pairs += st.top().second;

                if (st.top().first == h)
                    p.second += st.top().second;

                st.pop();
            }

        }

        st.push(std::move(p));
    }

    cout << n_pairs << endl;
    return 0;
}
