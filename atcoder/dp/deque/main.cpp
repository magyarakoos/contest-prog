#include <bits/stdc++.h>
using namespace std;

struct State {
    int l;
    int r;
    bool turn;
};

int N;
vector<int> a;
map<State, bool> m;

bool solve(State s) {
    if (m.count(s)) return m[s];

    
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    
}