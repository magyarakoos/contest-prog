#include <iostream>
#include <vector>
using namespace std;

// vector<int> buckets[1 << 20];
int mem[(int)1e6 + 1];

vector<int> merge(vector<int>& a, int l1, int r1, int l2,
                  int r2) {

    vector<int> c;
    int ai = 0, bi = 0, mi = 0;
    while (ai <= r1 && bi <= r2) {
        if (a[ai] < a[bi]) {
        } else {
        }
    }
    while (ai <= r1) c.push_back(a[ai++]);
    while (bi <= r2) c.push_back(b[bi++]);
    return c;
}

void sort(vector<int>& a, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        sort(a, l, m);
        sort(a, m + 1, r);

        merge(a, l, m, m + 1, r);
    }
}

void sort(vector<int>& a) {
    a = sort(a, 0, a.size() - 1);
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
