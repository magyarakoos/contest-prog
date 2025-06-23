#include <iostream>
#include <vector>
using namespace std;

const int LEN = 20;

vector<int> buckets[1 << LEN];

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        buckets[x & ((1 << LEN) - 1)].push_back(x);
    }
}
