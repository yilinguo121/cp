#include<bits/stdc++.h>
using namespace std;
bool t[805][805];
int main() {
	int n, m;
	while(cin >> n >> m) {
		memset(t, 0, sizeof(t));
		for (int i = 0;i < m;i++) {
			int a, b;
			cin >> a >> b;
			t[a][b] = 1;
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (t[i][k] and t[k][j]) {
						t[i][j] = true;
					}
				}
			}
		}
		int A, B;
		cin >> A >> B;
		if (t[A][B]) {
			cout << "Yes!!!" << '\n';
		}
		else {
			cout << "No!!!" << '\n';
		}
	}
}
