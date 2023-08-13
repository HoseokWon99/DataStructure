#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    vector<string> v(n);

    for (auto& s : v) {
        cin >> s;
        cin.ignore();
    }

    int tg;
    cin >> tg;

    string str;
    unsigned long long m;
    int num_case = 0;
    int tot = 0;

    do {
        str = std::move(accumulate(v.begin(), v.end(), string{}, plus<string>{}));
        m = stoull(str);
        if (m % tg == 0 ) ++num_case;
        ++tot;
    } while(next_permutation(v.begin(), v.end()));

    if (num_case == 0) {
        cout << "0/1" << endl;
    }
    else if (num_case == tot) {
        cout << "1/1" << endl;
    }
    else {
        int g = gcd(num_case, tot);
        cout << int(num_case / g) << '/' << int(tot / g) << endl;
    }

    return 0;
}
