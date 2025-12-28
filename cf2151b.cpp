#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		string s;
		cin >> n >> m >> s;
		set<int> st;
		while (m--) {
			int x;
			cin >> x;
			st.insert(x - 1);
		}
		int now = 0;
		for (auto x : s) {
			if (x == 'A') now++;
			else now = *st.lower_bound(now)++;
			st.insert(now);
		}
		cout << st.size() << '\n';
		for (auto x : st) cout << x + 1 << ' ';
		cout << '\n';
	}
}

