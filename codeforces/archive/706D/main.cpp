#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned;
constexpr int MAXN = 2e7;

int trie[MAXN][2], cnt[MAXN], node_count = 1;
map<u32, int> m;

u32 reverse(u32 x) {
    u32 res = 0;
    for (int i = 0; i < 32; i++) {
        res |= ((x >> (31 - i)) & 1) << i;
    }
    return res;
}

void insert(u32 x, int val) {
    int node = 1;
    for (int i = 0; i < 32; i++) {
        bool curr = (x >> i) & 1;
        if (trie[node][curr] == 0) {
            trie[node][curr] = ++node_count;
        }
        node = trie[node][curr];
        cnt[node] += val;
    }
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int Q;
    cin >> Q;

    while (Q--) {
        char c;
        u32 x;
        cin >> c >> x;
        x = reverse(x);

        if (c == '+') {
            m[x]++;
            if (m[x] == 1) {
                insert(x, 1);
            }
        }

        if (c == '-') {
            m[x]--;
            if (m[x] == 0) {
                insert(x, -1);
            }
        }

        if (c == '?') {
            u32 result = 0;
            int node = 1;

            for (int i = 0; i < 32; i++) {
                bool curr = (x >> i) & 1;

                if (cnt[trie[node][!curr]]) {
                    node = trie[node][!curr];
                    result |= !curr << i;
                } else {
                    node = trie[node][curr];
                    result |= curr << i;
                }
            }

            cout << max(
                reverse(x) ^ 0, 
                (reverse(x) ^ reverse(result))
            ) << "\n";
        }
    }
}
