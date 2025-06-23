#include <iostream>
#include <vector>
using namespace std;

// vector<int> buckets[1 << 20];

void sort(vector<int>& a, vector<int>& mem, int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;
    sort(a, mem, l, m);
    sort(a, mem, m + 1, r);

    mem = a;

    int ai = 0, bi = m + 1, si = 0;
    while (ai <= m && bi <= r) {
        if (mem[ai] < mem[bi]) {
            a[si++] = mem[ai++];
        } else {
            a[si++] = mem[bi++];
        }
    }
    cout << ai << " " << m << " " << bi << " ";

    while (ai <= m) a[si++] = mem[ai++];
    while (bi <= r) a[si++] = mem[bi++];

    cout << l << "-" << r<< ": ";
    for (int x : a) cout << x << " ";
    cout << "\n";
}

void sort(vector<int>& a) {
    vector<int> mem(a.size());
    sort(a, mem,0, a.size() - 1);
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
