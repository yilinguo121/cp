#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> st;
	int ans = 0;
	while (n--) {
		int x;
		cin >> x;
		if (!st.empty() and st.back().first == x) st.back().second++;
		else st.push_back({x, 1});
		ans++;
		if (st.back().first == st.back().second) {
			ans -= st.back().second;
			st.pop_back();
		}
		cout << ans << '\n';
	}
}

