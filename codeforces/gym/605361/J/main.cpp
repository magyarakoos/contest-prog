#include <iostream>
#include <vector>
using namespace std;

// vector<int> buckets[1 << 20];

vector<int> merge(const vector<int>& a, const vector<int>& b) {
    vector<int> c;
    int ai = 0, bi = 0;
    while (ai < a.size() && bi < b.size()) {
        if (a[ai] < b[bi]) {
            c.push_back(a[ai++]);
        } else {
            c.push_back(b[bi++]);
        }
    }
    while (ai < a.size()) c.push_back(a[ai++]);
    while (bi < b.size()) c.push_back(b[bi++]);
    return c;
}

void sort(const vector<int>& a, int l, int r) {
    if (left < right) {
    int m = (l + r) / 2;
    auto b = sort(a, l, m);
    auto c = sort(a, m + 1, r);


    cout << l << " " << m << " " << r << " " << a.size() << " " << b.size() << " " << c.size() << "\n";

    return merge(b, c);
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
