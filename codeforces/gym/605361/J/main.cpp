#include <iostream>
#include <vector>
using namespace std;

vector<int> buckets[1 << 20];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        buckets[x >> 10].push_back(x & ((1 << 10) - 1));
    }
    for (int i = 0; i < (1 << 20); i++) {

    }
}
