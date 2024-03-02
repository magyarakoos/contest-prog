#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

ifstream f("../input");

#ifdef LOCAL
#define cin f
#endif

int main() {
    int N, T;
    cin >> N >> T;
    map<ll, int> m;
    m[0] = N;
    vector<ll> scoreS(N);
    while (T--) {
        int A, B;
        cin >> A >> B;
        A--;


        m[scoreS[A]]--;
        m[scoreS[A] + B]++;

        cerr << scoreS[A] 

        for (const auto& [k, v] : m) {
            cerr << k << " : " << v << '\n';
        }

        cout << size(m) << '\n';
        cerr << '\n';
    }
}