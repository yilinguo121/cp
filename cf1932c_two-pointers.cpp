#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		for (int i = 0;i < n;i++) cin >> v[i];
		int l = 0, r = n - 1;
		string s;
		cin >> s;
		vector<int> a;
		for (auto c : s) {
			if (c == 'L') {
				a.push_back(v[l]);
				l++;
			}
			else {
				a.push_back(v[r]);
				r--;
			}
		}
		reverse(a.begin(), a.end());
		deque<int> ans;
		int now = 1;
		for (auto x : a) {
			now = (now * x) % m;
			ans.push_front(now);
		}
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
}

