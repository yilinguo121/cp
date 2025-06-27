#include<bits/stdc++.h>
using namespace std;
string s[1024];
void f(int lx, int ly, int rx, int ry) {
	int a[2] = {};
	for (int i = lx;i < rx;i++) {
		for (int j = ly;j < ry;j++) {
			a[s[j][i] - '0']++;
		}
	}
	if (a[0] and a[1]) {
		int x = (lx + rx) / 2;
		int y = (ly + ry) / 2;
		cout << 2;
		f(lx, ly, x, y);
		f(x, ly, rx, y);
		f(lx, y, x, ry);
		f(x, y, rx, ry);
	}
	else {
		if (a[0]) cout << 0;
		else cout << 1;
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) cin >> s[i];
	f(0, 0, n, n);
}
