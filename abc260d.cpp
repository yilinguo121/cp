#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	map<int, int> mp;
	map<int ,int> v;
	set<int> st;
	int ans[n + 1] = {};
	for (int i = 1;i <= n;i++) {
		int p;
		cin >> p;
		if (st.size() == 0) {
			st.insert(p);
			mp[p] = 1;
			v[p] = -1;
			if (mp[p] >= k) {
				st.erase(p);
				int j = p;
				while (1) {
					ans[j] = i;
					j = v[j];
					if (j == -1) break;
				}
			}
			continue;
		}
		auto pos = st.lower_bound(p);
		if (pos != st.end()) {
			mp[p] = mp[*pos] + 1;
			mp[*pos] = 0;
			v[p] = *pos;
			st.erase(pos);
			st.insert(p);
		}
		else {
			mp[p] = 1;
			st.insert(p);
			v[p] = -1;
		}
		if (mp[p] >= k) {
			int j = p;
			st.erase(p);
			while (1) {
				ans[j] = i;
				j = v[j];
				if (j == -1) break;
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		if (!ans[i]) cout << "-1\n";
		else cout << ans[i] <<'\n';
	}
}

