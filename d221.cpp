#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		priority_queue<int, vector<int>, greater<int>> v;
		for (int i = 0;i < n;i++) {
			int t;
			cin >> t;
			v.push(t);
		}
		int ans = 0;
		while(v.size() > 1) {
			int a = 0;
			a += v.top();
			v.pop();
			a += v.top();
			v.pop();
			v.push(a);
			ans += a;
		}
		cout << ans << '\n';
	}
}
