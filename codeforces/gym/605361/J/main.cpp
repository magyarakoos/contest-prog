#include <iostream>
#include <vector>
using namespace std;

const int LEN = 20;

vector<int> buckets[1 << LEN];

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int x : a) cout << x << " ";
    cout << "\n";
}
