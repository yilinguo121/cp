#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	vector<string> s(n);
	for (auto &x : s) cin >> x;
	vector<int> h(n), l(n), r(n);
	vector<int> st;
	long long ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (s[i][j] == '.') h[j]++;
			else h[j] = 0;
		}
		st.clear();
		for (int j = 0;j < n;j++) {
			while (!st.empty() and h[j] <= h[st.back()]) st.pop_back();
			l[j] = (st.empty() ? -1 : st.back());
			st.push_back(j);
		}
		st.clear();
		for (int j = n - 1;j >= 0;j--) {
			while (!st.empty() and h[j] < h[st.back()]) st.pop_back();
			r[j] = (st.empty() ? n : st.back());
			st.push_back(j);
		}
		for (int j = 0;j < n;j++) {
			ans += 1ll * h[j] * (j - l[j]) * (r[j] - j);
		}
	}
	cout << ans;
}

