#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll result;

void backtrack(vector<ll> a, vector<char> b) {
    if (a.size() == 1) {
        cout << a[0] << "\n";
        result = min(result, a[0]);
        return;
    }

    int N = a.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            char c = b.back();
            b.pop_back();
            ll x = a[i], y = a[j];
            a.erase(a.begin() + i);
            a.erase(a.begin() + j);

            a.push_back(c == '*' ? x * y : x + y);
            backtrack(a, b);

            a.pop_back();
            a.insert(a.begin() + j, y);
            a.insert(a.begin() + i, x);
            b.push_back(c);
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    vector<ll> a(4);
    vector<char> b(3);

    for (ll& x : a) cin >> x;
    for (char& c : b) cin >> c;

    result = LLONG_MAX;
    sort(a.begin(), a.end());
    do {
        sort(b.begin(), b.end());
        do {
            backtrack(a, b);
        } while (next_permutation(b.begin(), b.end()));
    } while (next_permutation(a.begin(), a.end()));

    cout << result << "\n";
}
