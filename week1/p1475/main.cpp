#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int nums[10];
    fill_n(nums, 10, 0);

    string roomId;
    cin >> roomId;

    for (char c : roomId) {
        int i = (int)c - 48;
        ++nums[i];
    }

    int z = nums[6] + nums[9];
    nums[6] = z % 2 == 0 ? z / 2 : (z + 1) / 2;

    cout << *max_element(nums, nums+9) << endl;
    return 0;
}