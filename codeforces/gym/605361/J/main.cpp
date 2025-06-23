#include <iostream>
#include <vector>
using namespace std;

// vector<int> buckets[1 << 20];

void sort(vector<int>& a, vector<int>& mem, int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;
    sort(a, l, m);
    sort(a, m + 1, r);

    int ai = 0, bi = m + 1, si = 0;
    while (ai <= m && bi <= r) {
        if (a[ai] < b[bi]) {
            mem[si++] = a[ai++];
        } else {
            mem[si++] = a[bi++];
        }
    }

    while (ai <= m) mem[si++] = a[ai++];
    while (bi <= m) mem[si++] = a[bi++];

    swap(a, mem);
}

void sort(vector<int>& a) {
    vector<int> mem(a.size());
    sort(a, mem, a.size() - 1);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a);
    for (int x : a) cout << x << " ";
    cout << "\n";
    // while (n--) {
        // int x;
        // cin >> x;
        // buckets[x >> 10].push_back(x & ((1 << 10) - 1));
    // }
    // for (int i = 0; i < (1 << 20); i++) {
    //     sort(buckets[i]);    
    // }
}
