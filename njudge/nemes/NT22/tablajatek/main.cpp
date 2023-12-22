#include <iostream>
#include <string>

using namespace std;

#define speed cin.tie(0); ios::sync_with_stdio(0)

string to_bin(int n) {
	if (n) {
		int pos = 31;
		while (!((n >> pos) & 1)) {
			pos--;
		}
		string s;
		while (pos >= 0) {
			s += to_string((n >> pos--) & 1);
		}
		return s;
	}
	return "0";
}

int main()
{
	speed;
	
	unsigned K, x = 0, y = 0;
	cin >> K;

	while (K--) {
		char move;
		cin >> move;
		if (move == '0') {
			x++;
			y = (y + 1) * 2 - 2;
		}
		else if (move == '1') {
			x++;
			y = (y + 1) * 2 - 1;
		}
		else if (move == '2') {
			x--;
			y = (y + 1) / 2 + ((y + 1) & 1) - 1;
		}
		else if (move == '3') y--;
		else if (move == '4') y++;
	}

	cout << x << '\n' << to_bin(y);
}
