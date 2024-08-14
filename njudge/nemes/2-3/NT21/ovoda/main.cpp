
#include <bits/stdc++.h>

#pragma region Utility

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

#define sum(v) accumulate(all(v), 0)
#define product(v, T) accumulate(all(v), 1, multiplies<T>())

using namespace std;
using ll = long long;
using point = array<int, 2>;

int max(point p) { return max(p[0], p[1]); }
int min(point p) { return min(p[0], p[1]); }

template <typename T>
vector<T> prefix_sum(const vector<T>& v) {
    vector<T> result(size(v));
    partial_sum(all(v), result.begin());
    return result;
}

#pragma endregion

#ifdef NATIVERUN
#define cin fin
#endif

int main() {
    #ifndef NATIVERUN
    speed;
    #else
    ifstream fin("input.txt");
    #endif

    int N, K;
    cin >> N >> K;

    vector<int> roleS(K), wantS(K);
    cinv(roleS);

    vector<int> orig_roleS = roleS;

    priority_queue<array<int, 3>> pq;
    
    vector<point> kidS(N);
    for (point& p : kidS) cin >> p[0];
    for (point& p : kidS) cin >> p[1];

    for (int i = 0; i < N; i++) {
        pq.push({kidS[i][1], kidS[i][0] - 1, i});
        wantS[kidS[i][0] - 1]++;
    }

    int total_cry = 0;
    vector<int> result(N);

    while (!pq.empty()) {
        auto [cry, kid, i] = pq.top(); pq.pop();

        if (cry == 0) {
            bool put = 0;
            for (int j = 0; j < K; j++) {
                if (roleS[j] == orig_roleS[j]) {
                    roleS[j]--;
                    result[i] = j;
                    put = 1;
                    break;
                }
            }
            if (put) continue;
            for (int j = 0; j < K; j++) {
                if (roleS[j] > 0) {
                    roleS[j]--;
                    result[i] = j;
                    break;
                }
            }
        }
        else if (roleS[kid] > 0) {
            roleS[kid]--;
            wantS[kid]--;
            result[i] = kid;
        } 
        else {
            total_cry += cry;
            pq.push({0, -1, i});
        }
    }

    cout << total_cry << '\n';
    for (int x : result) cout << x + 1 << ' ';
}
