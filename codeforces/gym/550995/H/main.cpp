#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    string s;
    cin >> N >> M >> s;

    map<array<char, 2>, int> adj;
    for (int i = 1; i < N; i++) adj[{s[i - 1], s[i]}]++;
}
