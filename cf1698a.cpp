#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0;i < n;i++) cin >> v[i];
		for (int i = 0;i < n;i++) {
			int sum = 0;
			for (int j = 0;j < n;j++) {
				if (j == i) continue;
				sum = (sum ^ v[j]);
			}
			if (sum == v[i]) {
				cout << v[i] << '\n';
				break;
			}
		}
	}
}

