#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

#define max_index(v) max_element(all(v)) - v.begin()
#define min_index(v) min_element(all(v)) - v.begin()
#define smax(x, y) x = max(x, y)
#define smin(x, y) x = min(x, y)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int max(point p) { return max(p[0], p[1]); }
int min(point p) { return min(p[0], p[1]); }

int main() {
    speed;

    int N, M;
    cin >> N >> M;
    
    vector<point> AB(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> AB[i][0] >> AB[i][1];
    }

    vector<int> result;
    int i = 1, pos = 1;

    while (pos < M) {
        int curr = -1;

        while (i <= N && AB[i][0] <= pos) {
            if (curr == -1 || AB[curr][1] < AB[i][1]) {
                curr = i;
            }
            i++; 
        }

        if (curr == -1) {
            cout << -1;
            exit(0);
        }

        pos = AB[curr][1];
        result.push_back(curr);
    }

    cout << size(result) - 1 << '\n';
    for (int x : result) cout << x << ' ';
}
