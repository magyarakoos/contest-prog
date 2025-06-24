#include <bits/stdc++.h>
using namespace std;

struct Tr {
    array<Tr*, 2> next;

    void add(int x) {
        auto cur = this;
        for (int i = 30; ~i; i--) {
            auto& nxt = cur->next[x >> i & 1];
            if (!nxt) nxt = new Tr();
            cur = nxt;
        }
    }

    int query(int x) {
        int y = 0;
        auto cur = this;
        for (int i = 30; ~i; i--) {
            if (cur->next[!(x >> i & 1)]) {
                y |= 1 << i;
                cur = cur->next[!(x >> i & 1)];
            } else {
                cur = cur->next[x >> i & 1];
            }
        }
        return y;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    Tr trie;
    int n, result = 0;
    cin >> n;
    vector<int> a(n + 1);
    trie.add(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
        trie.add(a[i]);
        result = max(result, trie.query(a[i]));
    }
    cout << result << "\n";
}
