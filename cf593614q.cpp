#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> a, h(n + 1);
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		cin >> h[i];
		while (!a.empty() and h[i] > h[a.back()]) {
			ans += i - a.back();
			a.pop_back();
		}
		if (a.empty()) a.push_back(i);
		else if (h[i] == h[a.back()]) {
			ans += i - a.back();
			a.back() = i;
		}
		else {
			ans += i - a.back();
			a.push_back(i);
		}
	}
	cout << ans;
}

