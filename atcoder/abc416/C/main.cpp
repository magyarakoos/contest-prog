#include <bits/stdc++.h>
using namespace std;
#define int int64_t

// https://stackoverflow.com/questions/16446374/generating-all-permutations-with-repetition
template <class Iter>
bool next_variation(
    Iter first, Iter last,
    const typename std::iterator_traits<Iter>::value_type
        max) {
    if (first == last)
        return false; // empty sequence (n==0)

    Iter i(last);
    --i; // Point to the rightmost element
    // Check if I can just increase it
    if (*i < max) {
        ++(*i);
        return true;
    } // Increase this element and return

    // Find the rightmost element to increase
    while (i != first) {
        *i = 0; // reset the right-hand element
        --i;    // point to the left adjacent
        if (*i < max) {
            ++(*i);
            return true;
        } // Increase this element and return
    }

    // If here all elements are the maximum symbol
    // (max=k-1), so there are no more variations
    // for(i=first; i!=last; ++i) *i = 0; // Should reset to
    // the lowest sequence (0)?
    return false;
} // 'next_variation'

#define cases 0
void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<string> a(n);
    for (string& s : a) cin >> s;
    sort(a.begin(), a.end());

    vector<string> sS;
    vector<int> perm(k);
    do {
        string s;
        for (int i = 0; i < k; i++) { s += a[perm[i]]; }
        sS.push_back(s);
    } while (
        next_variation(perm.begin(), perm.end(), n - 1));
    sort(sS.begin(), sS.end());
    cout << sS[x - 1] << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
