#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> c(m), a[m];
	for (int i = 0;i < m;i++) {
		cin >> c[i];
		for (int j = 0;j < c[i];j++) {
			int t;
			cin >> t;
			a[i].push_back(t);
		}
	}
	int ans = 0;
	for (int i = 1;i < (1 << m);i++) {
		set<int> st;
		for (int j = 0;j < m;j++) {
			if (i & (1 << j)) {
				for (int k = 0;k < c[j];k++) st.insert(a[j][k]);
			}
		}
		if (st.size() == n) ans++;
	}
	cout << ans;
}

