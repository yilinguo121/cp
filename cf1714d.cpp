#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
struct type{
	int l;
	int r;
	int id;
};
bool cmp (type a, type b) {
	return a.l < b.l;
}
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		string x;
		cin >> x;
		int n;
		cin >> n;
		vector<string> v(n);
		vector<type> a;
		for (int j = 0;j < n;j++) {
			cin >> v[j];
			string c = v[j];
			for (int i = 0;i < x.size();i++) {
				if (x.substr(i, c.size()) == c) a.push_back({i, i + (int)c.size() - 1, j});
			}
		}
		sort(a.begin(), a.end(), cmp);
		int last = 0;
		bool flag = 0;
		vector<pair<int, int>> ans;
		int pos = 0;
		while (last < x.size()) {
			int l = -1, r = -1, id = -1;
			while (pos < a.size() and a[pos].l <= last) {
				if (a[pos].r > r) {
					r = a[pos].r;
					l = a[pos].l;
					id = a[pos].id;
				}
				pos++;
			}
			if (r < last) break;
			last = r + 1;
			ans.push_back({id + 1, l + 1});
		}
		if (last < x.size()) cout << "-1\n";
		else {
			cout << ans.size() << '\n';
			for (auto [a, b] : ans) cout << a << ' ' << b << '\n';
		}
	}
}

