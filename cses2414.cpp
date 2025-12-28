#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> v;
int n;
int main() {
	cin >> n;
	v.resize(n * (n - 1) / 2);
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	int m = v.size();
	for (int k = 2;k < m;k++) {
		int t = v[0] + v[1] - v[k];
		if (t <= 0 or t % 2) continue;
		int a0 = t / 2;
		int a1 = v[0] - a0;
		int a2 = v[1] - a0;
		if (a1 <= 0 or a2 <= 0) continue;
		multiset<int> st(v.begin(), v.end());
		if (st.find(a0 + a1) == st.end()) continue;
		if (st.find(a0 + a2) == st.end()) continue;
		if (st.find(a1 + a2) == st.end()) continue;
		st.erase(st.find(a0 + a1));
		st.erase(st.find(a0 + a2));
		st.erase(st.find(a1 + a2));
		vector<int> ans;
		ans.push_back(a0);
		ans.push_back(a1);
		ans.push_back(a2);
		while (ans.size() < n) {
			int ms = *st.begin();
			int p = ms - a0;
			if (p <= 0) break;
			for (auto q : ans) {
				if (st.find(p + q) == st.end()) break;
				st.erase(st.find(p + q));
			}
			ans.push_back(p);
		}
		if (ans.size() == n and st.empty()) {
			for (auto x : ans) cout << x << ' ';
			return 0;
		}
	}
}
