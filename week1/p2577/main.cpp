#include <iostream>
#include <string>

using namespace std;

int main() {
    int cnts[10];
    fill_n(cnts, 10, 0);

    auto s = to_string([](istream& in){
        int abc[3];
        for (int& x : abc) in >> x;
        return abc[0]*abc[1]*abc[2];
    }(cin));

    for (char c : s) {
        int i = int(c) - 48;
        ++cnts[i];
    }

    for (int cnt : cnts)
        cout << cnt << ' ';

    cout << endl;
    return 0;
}
