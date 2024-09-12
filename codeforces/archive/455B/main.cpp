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

bool dfs(int i) {
    for (int j = 0; j < 26; j++) {
        if (trie[i][j]) {}
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

    bool w = 0;
    for (int i = 0; i < 26; i++) {
        if (dfs(trie[1][i])) w = 1;
    }

    cout << (K & 1 ? w : !w);
}
