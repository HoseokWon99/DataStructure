#include <iostream>

using namespace std;

int main() {
    int total, batch;
    cin >> total >> batch;
    cin.clear();

    int config[6][2] = { 0, };
    int s, y;

    for (int i = 0; i != total; ++i) {
        cin >> s >> y;
        ++config[y-1][s];
        cin.clear();
    }

    int n_rooms = 0;

    for (auto& X : config) {
        for (auto x : X) {
            int m = x / batch;
            int r = x % batch;
            n_rooms += r == 0 ? m : m + 1;
        }
    }

    cout << n_rooms << endl;
    return 0;
}


