#include <bits/stdc++.h>

using namespace std;

#define speed cin.tie(0); ios::sync_with_stdio(0)

#include <bitset>

struct BinaryBigInt {
private:
    bitset<500> a;
public:
    // add exactly one to the number
    void add() {
        if (!a[0]) {
            a[0] = 1;
        } else {
            int i = 0;
            while (a[i] == 1) {
                a[i] = 0;
                i++;
            }
            a[i] = 1;
        }
    }

    // subtract exactly one from the number
    void sub() {
        if (a[0]) {
            a[0] = 0;
        } else {
            int i = 0;
            while (a[i] == 0) {
                a[i] = 1;
                i++;
            }
            a[i] = 0;
        }
    }

    // multiply by two (<< 1)
    void mul2() {
        a <<= 1;
    }

    // bivide by two (>> 1)
    void div2() {
        a >>= 1;
    }

    // parity
    bool parity() const {
        return a[0];
    }

	void print() const {
		// ignore leading zeroes
		int i = 499;
		for (i = 499; i >= 0; i--) {
			if (a[i]) break;
		}

		if (i < 0) {
			cout << 0;
		} else {
			for (; i >= 0; i--) {
				cout << a[i];
			}
		}
	}
};


int main()
{
	speed;
	
	int K, x = 0;
	cin >> K;
	BinaryBigInt y;

	while (K--) {
		char move;
		cin >> move;
		if (move == '0') {
			x++;
			y.add();
			y.mul2();
			y.sub();
			y.sub();
		}
		else if (move == '1') {
			x++;
			y.add();
			y.mul2();
			y.sub();
		}
		else if (move == '2') {
			x--;
			y.add();
			bool par = y.parity();
			y.div2();
			y.sub();
			if (par) y.add();
		}
		else if (move == '3') y.sub();
		else if (move == '4') y.add();
	}

	cout << x << '\n';
	y.print();
}
