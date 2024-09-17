#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    for (int& x : P) cin >> x;
    for (int& x : Q) cin >> x;
}
