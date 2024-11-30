#include <iostream>
#include <vector>
using namespace std;

vector<int> A;
vector<vector<int>> result;
int N, M;

void backtrack(int i) {
    if (i == N) return;

    if (i == 0) {
        for (int j = 1; j <= M - 10 * (N - i - 1); j++) {
            A.push_back(j);
            backtrack(i + 1);
            A.pop_back();
        }
        return;
    }

    for (int j = A.back() + 10; j <= M - 10 * (N - i - 1);
         j++) {
        A.push_back(j);
        if (i == N - 1) result.push_back(A);
        backtrack(i + 1);
        A.pop_back();
    }
}

int main() {
    cin >> N >> M;
    backtrack(0);
    cout << result.size() << "\n";
    for (const auto& row : result) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
}
