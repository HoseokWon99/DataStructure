#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;

    cin >> s1;
    cin.clear();
    cin >> s2;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    string s3;

    set_symmetric_difference(
            s1.begin(), s1.end(),
            s2.begin(), s2.end(),
            back_inserter(s3)
    );

    cout << s3.size() << endl;
    return 0;
}
