#include <iostream>
#include <ios>
#include <vector>
#include <string>
#include <queue>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v;

    v.reserve([](istream& in){
        size_t n;
        in >> n;
        in.ignore();
        return n;
    }(cin));

    string s;
    s.reserve(5);



    queue<int> q;

    for (auto& x : v) {

    }

    return 0;
}
