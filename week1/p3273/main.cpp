#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums([](istream& in){
        vector<int>::size_type n;
        in >> n;
        in.clear();
        return n;
    }(cin));

    for (auto& num : nums) cin >> num;
    cin.clear();

    int x;
    cin >> x;
    int x_half = floor(x / 2);

    auto mid = partition(nums.begin(), nums.end(), [&x_half](int elem){ return elem <= x_half; });
    auto end = partition(mid, nums.end(), [&x](int elem){ return elem < x; });
    sort(nums.begin(), mid);
    sort(mid, end);

    int cnt = 0;
    auto limit = end - 1;

    for (auto i = nums.begin(); i != mid; ++i) {

        for (auto j = limit; j >= mid; --j) {

            if (*i + *j == x) {
                ++cnt;
                limit = j - 1;
                break;
            }

        }

    }

    cout << cnt << endl;
    return 0;
}

