#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		v.push_back(t - 1);
	}
	vector<int> a(n);
	int ans = 0;
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		if (a[v[i]] != 0) {
			ans += min(a[v[i]], t);
			a[v[i]] = max(a[v[i]], t);
		}
		else {
			a[v[i]] = t;
		}
	}
	cout << ans << '\n';
}
