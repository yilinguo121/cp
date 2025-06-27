#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	vector<int> v(n + 1), t(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		t[v[i]] = i;
	}
	vector<int> st, l(n + 1), r(n + 1);
	for (int i = 1;i <= n;i++) {
		int last = 0;
		while (!st.empty() and t[st.back()] > t[i]) {
			last = st.back();
			st.pop_back();
		}
		l[i] = last;
		if (!st.empty()) r[st.back()] = i;
		st.push_back(i);
	}
	vector<int> ans(n + 1);
	for (int i = 1;i <= n;i++) {
		if (l[i]) ans[l[i]] = i;
		if (r[i]) ans[r[i]] = i;
	}
	for (int i = 1;i <= n;i++) cout << ans[i] << '\n';
}

