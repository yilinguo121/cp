#include <bits/stdc++.h>
using namespace std;
int main() {
	int nx = 0, ny = 0;
	for (int i = 0;i < 3;i++) {
		int x, y;
		cin >> x >> y;
		nx = (nx ^ x);
		ny = (ny ^ y);
	}
	cout << nx << ' ' << ny;
}

