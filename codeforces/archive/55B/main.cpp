#include <climits>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

char op[3];
ll result = LLONG_MAX;

void backtrack(vector<ll> a) {
    int n = a.size();
    if (n == 1) {
        result = min(result, a[0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            vector<ll> a2 = a;

            a2.push_back(op[4 - n] == '*' ? a[i] * a[j] : a[i] + a[j]);
            a2.erase(a2.begin() + i);
            a2.erase(a2.begin() + j);

            backtrack(a2);
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    vector<ll> a(4);
    for (ll& x : a) cin >> x;
    for (int i = 0; i < 3; i++) cin >> op[i];

    backtrack(a);

    cout << result << "\n";
}
