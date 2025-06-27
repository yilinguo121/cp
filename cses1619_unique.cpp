#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), v;
	for (int i = 0;i < n;i++) {
		cin >> a[i] >> b[i];
		v.push_back(a[i]);
		v.push_back(b[i]);
	}
	sort(v.begin(), v.end());
	vector<int> t(2 * n);
	for (int i = 0;i < n;i++) {
		t[lower_bound(v.begin(), v.end(), a[i]) - v.begin()]++;
		t[lower_bound(v.begin(), v.end(), b[i]) - v.begin() + 1]--;
	}
	int sum = 0, ans = 0;
	for (auto x : t) {
		sum += x;
		ans = max(ans, sum);
	}
	cout << ans;
}

