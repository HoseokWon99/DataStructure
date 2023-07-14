#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums([](istream& in){
        vector<int>::size_type n;
        in >> n;
        in.clear();
        return n;
    }(cin));

    for (auto& num : nums)
        cin >> num;

    cin.clear();

    int x;
    cin >> x;

    int cnt = 0;
    for (int num : nums)
        if (num == x) cnt += 1;

    cout << cnt << endl;
    return 0;
}