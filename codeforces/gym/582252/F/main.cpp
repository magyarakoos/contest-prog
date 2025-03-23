#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 1;

bitset<MAXN> s;
vector<int> m[MAXN];

int main() {
    for (int i = 2; i < MAXN; i++) {
        for (int j = i; j < MAXN * s[i]; j++) {
            s[j] = 0;
            m[j].push_back(i);
        }
    }
    int N, x;
    cin >> N;
    while (cin >> x && N--) { cout << x << "\n"; }
}
