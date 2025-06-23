#include <iostream>
#include <vector>
using namespace std;

vector<int> buckets[1 << 20];
int swap[1e6 + 1];

void sort(vector<int>& a, int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;
    sort(a, l, m);
    sort(a, m + 1, r);

    int ai = 0, bi = m + 1, si = 0;
    while (ai <= m && bi <= r) {
        if (a[ai] < b[bi]) {
            swap[si++] = a[ai++];
        }
    }
}

void sort(vector<int>& a) {
    sort(a, 0, a.size() - 1);
}

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
        sort(buckets[i]);    
    }
}
