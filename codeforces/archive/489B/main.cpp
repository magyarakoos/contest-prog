#include <bits/stdc++.h>
 
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
 
using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> b(N);
    cinv(b);
    sort(all(b));
    
    int M;
    cin >> M;
    vector<int> g(M);
    cinv(g);
    sort(all(g));

    int bp = 0, gp = 0, result = 0;

    while (bp < N) {
        if (abs(b[bp] - g[gp]) <= 1) {
            result++;
            bp++;
            gp++;
        } 
        else if (b[bp] < g[gp]) {
            bp++;
        }
        else {
            gp++;
        }
    }

    cout << result;
}
