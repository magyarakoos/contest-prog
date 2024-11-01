#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    unordered_set<int> s;
    s.insert(a[0]);
}
