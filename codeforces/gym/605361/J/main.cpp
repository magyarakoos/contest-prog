#include <iostream>
#include <vector>
using namespace std;

// vector<int> buckets[1 << 20];

vector<int> merge(vector<int> a, vector<int> b) {

}

vector<int> sort(vector<int>& a, int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;
    auto b = sort(a, l, m);
    auto c = sort(a, m + 1, r);
    a = merge(b, c);
}

void sort(vector<int>& a) {
    vector<int> mem(a.size());
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
