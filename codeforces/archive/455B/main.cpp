#include <iostream>

using namespace std;

const int MAXN = 1e5 + 5;

int trie[MAXN][26], cnt[MAXN], node_count = 1;
bool win[MAXN], lose[MAXN];

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
    bool has_ch = 0;
    for (int j = 0; j < 26; j++) {
        if (trie[i][j]) {
            has_ch = 1;
            dfs(trie[i][j]);
            win[i] |= !win[trie[i][j]];
            lose[i] |= !lose[trie[i][j]];
        }
    }
    if (!has_ch) win[i] = 1;
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
    win[1] = lose[1] = 0;
    for (int i = 0; i < 26; i++) {
        win[i] |= win[trie[1][i]];
        lose[i] |= lose[trie[1][i]];
    }

    if (win[1] && lose[1]) cout << "First\n";
    if (win[1] && !lose[1]) cout << (K & 1 ? "First\n" : "Second\n");
    if (!win[1] && lose[1])
        ;
    if (!win[1] && !lose[1]) assert(0);
}
