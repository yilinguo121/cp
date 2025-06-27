#include <bits/stdc++.h>
using namespace std;
int main() {
	int q;
	int a[10] = {
	0b1110111, //0
	0b0010010, //1
	0b1011101, //2
	0b1011011, //3
	0b0111010, //4
	0b1101011, //5
	0b1101111, //6
	0b1110010, //7
	0b1111111, //8
	0b1111011, //9
	};
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		int on = 0, off = 0;
		for (int i = 0;i < n;i++) {
			int p = s1[i] - '0';
			int q = s2[i] - '0';
			off += __builtin_popcount(a[p] & ~a[q]);
			on += __builtin_popcount(a[p] ^ a[q]) - __builtin_popcount(a[p] & ~a[q]);
		}
		cout << on << ' ' << off << '\n';
	}
}

