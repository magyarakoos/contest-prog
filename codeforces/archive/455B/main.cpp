#include <iostream>

using namespace std;

const int MAXN = 1e5 + 5;

int trie[MAXN][26], cnt[MAXN], node_count = 1;
bool win[MAXN][26], lose[MAXN][26];

void insert(const string& s) {
    int node = 1;
    for (char c : s) {
        int a = c - 'a';
        if (!trie[node][a]) { trie[node][a] = ++node_count; }
        node = trie[node][a];
        cnt[node]++;
    }
}

void dfs(int i) {
    for (int j = 0; j < 26; j++) {
        if (trie[i][j]) {
            dfs(trie[i][j]);
            win[i][j] |= !win[trie[i][j]][j];
        }
    }
    return result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        insert(s);
    }

    dfs(1);
}
