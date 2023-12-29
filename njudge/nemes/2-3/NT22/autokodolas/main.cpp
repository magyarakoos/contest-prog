#include <iostream>

using namespace std;
using ll = long long;

#define speed cin.tie(0); ios::sync_with_stdio(0)

int count_set(ll n) {
	int c = 0;
	while (n) {
		n = n & (n - 1);
		c++;
	}
	return c;
}

void unset_until(ll& n, int pos) {
	for (int i = 0; i < pos; i++) n >>= 1;
	for (int i = 0; i < pos; i++) n <<= 1;
}

int main()
{
	speed;
	
	ll M, N, O;
	cin >> N;

	M = O = N;
	
	if (M & 1) {
		int pos = 1;
		while ((M >> pos) & 1) pos++;
		
		if (pos == count_set(M)) {
			M = -1;
		}
		else {
			int zero_c = pos;
			while (!((M >> zero_c) & 1)) zero_c++;
			zero_c -= pos;
			unset_until(M, pos + zero_c + 1);
			M |= ((1LL << (pos + 1)) - 1) << (zero_c - 1);
		}
	}
	else {
		int pos = 1;
		while (!((M >> pos) & 1)) pos++;
		M ^= ((1LL << pos) | (1LL << (pos - 1)));
	}

	int pos = 0;
	while (!((O >> pos) & 1) || ((O >> (pos + 1)) & 1)) pos++;

	O ^= (1LL << pos) | (1LL << (pos + 1));
	
	int zero_c = 0;
	while (!((O >> zero_c) & 1) && zero_c < pos) zero_c++;

	int one_c = zero_c;
	while (((O >> one_c) & 1) && one_c < pos) one_c++;
	one_c -= zero_c;

	unset_until(O, zero_c + one_c);
	O |= (1LL << one_c) - 1;

	cout << M << '\n' << O;
}
