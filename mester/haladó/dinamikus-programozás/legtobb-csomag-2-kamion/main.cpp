// it is important to note that this does not work
#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

vector<int> v;
vector<bool> put; // a jobboldaliba raktuk-e
int K, N;

int dp(int a, int b, int i) {
    cerr << a << ' ' << b << ' ' << i << '\n';
    if (a + v[i] > K && b + v[i] > K) {
        return i;
    }

    int left = -1, right = -1;
    if (a + v[i] <= K) left = dp(a + v[i], b, i + 1);
    if (b + v[i] <= K) right = dp(a, b + v[i], i + 1);

    if (left != -1 && right != -1) {
        put[i] = left < right;
    }
    else {
        put[i] = left == -1;
    }

    return max(left, right);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> K >> N;

    v.resize(N);    
    put.resize(N);
    cinv(v);

    int result = dp(v[0], 0, 1);

    cerr << '\n';
    cout << result << '\n';

    for (int i = 0; i < result; i++) {
        if (put[i]) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';

    for (int i = 0; i < result; i++) {
        if (!put[i]) {
            cout << i + 1 <<  ' ';
        }
    }
    cout << '\n';
}
