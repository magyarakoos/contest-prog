#include <bits/stdc++.h>
using namespace std;

map<array<char, 2>, int> adj;
map<int, int> cache;

int dp(int mask) {}

int main() {
    int N, M;
    string s;
    cin >> N >> M >> s;

    for (int i = 1; i < N; i++) adj[{s[i - 1], s[i]}]++;
}
