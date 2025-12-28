#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
struct FastHash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		x = x ^ (x >> 31);
		return x;
	}
	size_t operator()(long long x) const {
		static const uint64_t FIXED_RANDOM =
			chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
signed main() {
	IO
	int n, k;
	cin >> n >> k;
	unordered_map<int, int, FastHash> cnt;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	for (int i = 0;i < (1 << (n / 2));i++) {
		int sum = 0;
		for (int j = 0;j < n / 2;j++) if (i & (1 << j)) sum += v[j];
		cnt[sum]++;
	}
	int ans = 0;
	for (int i = 0;i < (1 << ((n + 1) / 2));i++) {
		int sum = 0;
		for (int j = 0;j < (n + 1) / 2;j++) if (i & (1 << j)) sum += v[j + n / 2];
		if (cnt.count(k - sum)) ans += cnt[k - sum];
	}
	cout << ans;
}
