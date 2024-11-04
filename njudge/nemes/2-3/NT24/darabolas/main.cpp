#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    ll M, N;
    cin >> M >> N;

    vector<ll> MC(M - 1), NC(N - 1);
    for (ll& x : MC) cin >> x;
    for (ll& x : NC) cin >> x;

    ll Ndb = 1, Mdb = 1;
}
