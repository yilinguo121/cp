#include<bits/stdc++.h>
using namespace std;
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
char c[1005][1005];
bool v[1005][1005];
int n, m;
bool check(int i, int j) {
	if (i < 0 or j < 0) {
		return 0;
	}
	if (i >= n or j >= m) {
		return 0;
	}
	if (c[i][j] == '#') {
		return 0;
	}
	return 1;
}
void f(int i, int j) {
	v[i][j] = 1;
	int a = i;
	int b = j;
	for (int t = 0;t < 4;t++) {
		a = i + x[t];
		b = j + y[t];
		if (check(a, b) and !v[a][b]) {
			f(a, b);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> c[i][j];
		}
	}
	int ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (c[i][j] == '.' and !v[i][j]) {
				f(i, j);
				ans++;
			}
		}
	}
	cout << ans << '\n';
}
