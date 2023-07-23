#include <iostream>
#include <ios>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n_towers;
    cin >> n_towers;
    cin.ignore();

    vector<int> towers(n_towers);
    vector<int> accepts(n_towers);

    cin >> towers[0];
    accepts[0] = 0;

    for (int i = 1; i != n_towers; ++i) {
        cin >> towers[i];

        if (towers[i] > towers[i-1]) {
            auto j = accepts[i-1] - 1;

            while (j >= 0 && towers[j] < towers[i])
                --j;

            accepts[i] = j + 1;
        }
        else {
            accepts[i] = i;
        }
    }

    for (auto a : accepts)
        cout << a << ' ';

    cout.flush();
    return 0;
}
