#include<bits/stdc++.h>
using namespace std;
int n, m, k, ans = 0;
int a[105][20];
vector<bool> v(20);
bool check() {
	for (int i = 0;i < m;i++) {
		int t = 0;
		for (int j = 1;j <= a[i][0];j++) {
			if (v[a[i][j]]) {
				t++;
			}
		}
		if (t < k and a[i][a[i][0] + 1] == 1 or t >= k and a[i][a[i][0] + 1] == 0) {
			return 0;
		}
	}
	return 1;
}
void f (int i) {
	if (i == n + 1) {
		if (check()) {
			ans++;
		}
		return;
	}
	v[i] = 0;
	f(i + 1);
	v[i] = 1;
	f(i + 1);
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0;i < m;i++) {
		cin >> a[i][0];
		for (int j = 1;j <= a[i][0];j++) {
			cin >> a[i][j];
		}
		char c;
		cin >> c;
		if (c == 'o') {
			a[i][a[i][0] + 1] = 1;
		}
		else {
			a[i][a[i][0] + 1] = 0;
		}
	}
	f(1);
	cout << ans;
}

