#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (auto &x : s) cin >> x;
	vector<int> h(m), l(m), r(m);
	vector<int> st;
	long long ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (s[i][j] == '.') h[j]++;
			else h[j] = 0;
		}
		st.clear();
		for (int j = 0;j < m;j++) {
			while (!st.empty() and h[j] <= h[st.back()]) st.pop_back();
			l[j] = (st.empty() ? -1 : st.back());
			st.push_back(j);
		}
		st.clear();
		for (int j = m - 1;j >= 0;j--) {
			while (!st.empty() and h[j] < h[st.back()]) st.pop_back();
			r[j] = (st.empty() ? n : st.back());
			st.push_back(j);
		}
		for (int j = 0;j < m;j++) ans = max(ans, 1ll * h[j] * (r[j] - l[j]));
	}
	cout << ans;
}
