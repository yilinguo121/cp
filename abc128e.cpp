#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, q;
	cin >> n >> q;
	vector<array<int, 3>> v;
	for (int i = 0;i < n;i++) {
		int s, t, x;
		cin >> s >> t >> x;
		v.push_back({s - x, 1, x});
		v.push_back({t - x, 0, x});
	}
	sort(v.begin(), v.end());
	int i = 0;
	set<int> st;
	while (q--) {
		int x;
		cin >> x;
		while (i < v.size() and v[i][0] <= x) {
			if (v[i][1]) st.insert(v[i++][2]);
			else st.erase(v[i++][2]);
		}
		cout << (st.empty() ? -1 : *st.begin()) << '\n';
	}
}
