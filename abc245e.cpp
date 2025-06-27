#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n), b(m);
	for (auto &[x, y] : a) cin >> x;
	for (auto &[x, y] : a) cin >> y;
	for (auto &[x, y] : b) cin >> x;
	for (auto &[x, y] : b) cin >> y;
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	multiset<int> st;
	for (int i = 0, j = 0;i < n;i++) {
		while (j < m and b[j].first >= a[i].first) {
			st.insert(b[j].second);
			j++;
		}
		auto it = st.lower_bound(a[i].second);
		if (it == st.end()) {
			cout << "No";
			return 0;
		}
		st.erase(it);
	}
	cout << "Yes";
}
