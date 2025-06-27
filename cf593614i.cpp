#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	sort(v.begin(), v.end());
	long long ans = 0;
	for (int k = 2;k < n;k++) {
		for (int i = 0, j = k;i < k;i++) {
			while (j - 1 > i and v[i] + v[j - 1] > v[k]) j--;
			ans += k - max(i + 1, j);
		}
	}
	cout << ans;
}
