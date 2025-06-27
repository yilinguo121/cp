#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int nx = 0;
	int ny = 0;
	int x[4] = {0, 1, 0, -1};
	int y[4] = {1, 0, -1, 0};
	while (n--) {
		int t, k;
		cin >> t >> k;
		nx += x[t] * k;
		ny += y[t] * k;
	}
	cout << nx << ' ' << ny;
}

