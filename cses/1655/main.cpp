#include <bits/stdc++.h>
using namespace std;
#define int int64_t

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
};

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }

    Tr* trie = new Tr();
}
