#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		deque<int> v(n);
		for (int i = 0;i < n;i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int ans = 0;
		while (v.size() > 1) {
			int sum = v[0];
			v.pop_front();
			sum += v[0];
			v.pop_front();
			ans += sum;
			v.push_back(sum);
			sort(v.begin(), v.end());
		}
		cout << ans << '\n';
	}
}
