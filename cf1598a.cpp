#include<bits/stdc++.h>
using namespace std;
int main() {
	int m;
	cin >> m;
	for (int j = 0;j < m;j++) {
		int n;
		cin >> n;
		string s[2];
		for (int i = 0;i < 2;i++) {
			cin >> s[i];
		}
		int x[5] = {-1, -1, 0, 1, 1};
		int y[5] = {0, 1, 1, 1, 0};
		int a = 0, b = 0;
		while (1) {
			if (a == 1 and b == n - 1) {
				cout << "Yes" << '\n';
				break;
			}
			int t = 0;
			for (int i = 0;i < 5;i++) {
				if (a + x[i] >= 0 and a + x[i] < 2 and b + y[i] >= 0 and b + y[i] < n and s[a + x[i]][b + y[i]] == '0') {
					a += x[i];
					b += y[i];
					s[a][b] = '1';
					t++;
					break;
				}
			}
			if (t == 0) {
				cout << "No" << '\n';
				break;
			}
		}
	}
}
