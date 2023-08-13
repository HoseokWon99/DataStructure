#include <iostream>
#include <ios>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    cin.ignore();

    deque<int> deq;

    for (int i = 1; i <= n; ++i)
        deq.push_back(i);

    int mid = (n - 1) / 2;
    int tg = 0;
    int cnt = 0;
    int x;

    while(--k) {
        cin >> x;

        for (int i = 0; i != n; ++i) {
            if (deq[i] == x) break;
            ++tg;
        }

        if (tg <= mid) {

            while (deq.front() != x) {
                deq.push_back(deq.front());
                deq.pop_front();
                ++cnt;
            }

        }
        else {

            while (deq.front() != x) {
                deq.push_front(deq.back());
                deq.pop_back();
                ++cnt;
            }

        }

        deq.pop_front();
        --n;
    }

    return 0;
}
