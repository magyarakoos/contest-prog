#include <bits/stdc++.h>
using namespace std;

int N, M;
int adj[26][26];
map<int, int> cache;
map<int, vector<int>> order;

int dp(int mask) {
    if (cache.count(mask)) return cache[mask];
    if (mask == 0) return cache[mask] = 0;

    int result = INT_MAX;
    for (int i = 0; i < M; i++) {
        if (mask >> i & 1) {
            int cost = 0;

            int nmask = mask & ~(1 << i);
        }
    }
    return cache[mask] = result;
}

int main() {
    string s;
    cin >> N >> M >> s;
    for (int i = 1; i < N; i++) {
        adj[s[i - 1] - 'a'][s[i] - 'a']++;
    }
}
