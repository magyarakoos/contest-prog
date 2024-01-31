#include <bits/stdc++.h>
using namespace std;

struct Record {
    string key;
    int score;
};

array<Record, 1000> playerS;
int length;

int GetRecord(const string& s) {
    for (int i = 0; i < length; i++) {
        if (playerS[i].key == s) {
            return i;
        }
    }
    return -1;
}

int main() {
    int N;
    cin >> N;

    int result = INT_MIN, playerID = 0;

    for (int i = 0; i < N; i++) {
        string s;
        int x;
        cin >> s >> x;

        int index = GetRecord(s);

        if (index == -1) {
            playerS[length] = {s, x};
            index = length;
            length++;
        } else {
            playerS[index].score += x;
        }

        if (result < playerS[index].score) {
            result = playerS[index].score;
            playerID = index;
        }
    }

    cout << playerS[playerID].key;
}
