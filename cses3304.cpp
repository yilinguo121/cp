#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, q;
	cin >> n >> q;
	vector<int> h(n + 1), a(n + 1);
	vector<int> st;
	for (int i = 1;i <= n;i++) {
		cin >> h[i];
		while (!st.empty() and h[i] > h[st.back()]) st.pop_back();
		a[i] = (st.empty() ? 0 : st.back());
		st.push_back(i);
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = 0;
		for (int i = x;i <= y;i++) {
			if (a[i] < x) ans++;
		}
		cout << ans << '\n';
	}
}
