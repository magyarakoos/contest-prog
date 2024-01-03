#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using u32 = unsigned int;

const int BITS = 200;
const int WORD_SIZE = 32;

// skull emoji
struct Integer {
private:
    vector<u32> value;
public:
    Integer() : value((BITS + WORD_SIZE - 1) / WORD_SIZE, 0) {}

    void add() {
        for (size_t i = 0; i < value.size(); ++i) {
            if (value[i] == UINT_MAX) {
                value[i] = 0;
            } else {
                ++value[i];
                break;
            }
        }
    }

    void sub() {
        for (size_t i = 0; i < value.size(); ++i) {
            if (value[i] == 0) {
                value[i] = UINT_MAX;
            } else {
                --value[i];
                break;
            }
        }
    }

    void div3() {
        u32 carry = 0;
        for (int i = value.size() - 1; i >= 0; --i) {
            ull curr = ((ull)(value[i]) + (ull)(carry) * (UINT_MAX + 1));
            value[i] = (u32)(curr / 3);
            carry = (u32)(curr % 3);
        }
    }

    void mul3() {
        u32 carry = 0;
        for (size_t i = 0; i < value.size(); ++i) {
            ull curr = (ull)(value[i]) * 3 + carry;
            value[i] = (u32)(curr);
            carry = (u32)(curr >> WORD_SIZE);
        }
    }

    void print() const {
        vector<int> result;
        Integer tmp = *this;

        while (tmp.value != vector<u32>(tmp.value.size(), 0)) {
            int rem = 0;
            for (size_t i = tmp.value.size(); i > 0; --i) {
                ull curr = ((ull)rem << WORD_SIZE) + tmp.value[i - 1];
                tmp.value[i - 1] = (u32)curr / 3;
                rem = curr % 3;
            }
            result.push_back(rem);
        }

        if (result.empty()) {
            cout << '0';
        } else {
            for (int i = result.size() - 1; i >= 0; i--) {
                cout << result[i];
            }
        }
    }

};

int main() {
    speed;

    ll K, row = 0;
    cin >> K;

    Integer col;

    while (K--) {
        char m;
        cin >> m;

        if (m == '0') {
            row++;
            col.mul3();
        }
        else if (m == '1') {
            row++;
            col.mul3();
            col.add();
        }
        else if (m == '2') {
            row++;
            col.mul3();
            col.add();
            col.add();
        }
        else if (m == '3') {
            row--;
            col.div3();
        }
        else if (m == '4') {
            col.sub();
        }
        else {
            col.add();
        }
    }

    cout << row << '\n';
    col.print();
}
