#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> cnt(200001);
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		cnt[t]++;
	}
	long long ans = 0;
	for (int i = 1;i <= 200000;i++) {
		for (int j = 1;j * i <= 200000;j++) {
			ans += 1ll * cnt[i] * cnt[j] * cnt[i * j];
		}
	}
	cout << ans;
}

