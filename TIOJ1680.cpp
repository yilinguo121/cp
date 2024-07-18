#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int a[m];
	int d[m + 1];
	for (int i = 0;i < m;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < n;i++) {
		vector<int> v(m);
		for (int j = 0;j < m + 1;j++){
			cin >> d[j];
		}
		int t = m - 1;
		if (d[m] >= d[m - 1]) {
			v[t] = 1;
		}
		else {
			v[t] = 0;
		}
		t--;
		for (int j = m;t > -1;t--, j--) {
			if (abs(d[j] - d[j - 1]) >= d[j - 2]) {
				v[t] = 1;
			}
			else {
				v[t] = 0;
			}

		}
		int ans = 0;
		for (int j = 0;j < m;j++) {
			if (a[j] != v[j]) {
				ans++;
			}
		}
		if (ans == 0) {
			for (int j = 0;j < m;j++) {
				cout << d[j] << ' ';
			}
			cout << d[m];
		}
	}
}
