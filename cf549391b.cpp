#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000001;
int a[N];
int b[N];
vector<pair<int, int>> l;
vector<pair<int, int>> g;
signed main() {
	int n, m;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int p, k;
		cin >> p >> k;
		a[p] += k;
	}
	cin >> m;
	for (int i = 0;i < m;i++) {
		int p, k;
		cin >> p >> k;
		b[p] += k;
	}
	for (int i = 1;i < N;i++) {
		if (a[i] and b[i]) {
			g.push_back({i, min(a[i], b[i])});
		}
		if (a[i] or b[i]) {
			l.push_back({i, max(a[i], b[i])});
		}
	}
	int size;
	size = g.size();
	cout << size << '\n';
	for (int i = 0;i < size;i++) {
		cout << g[i].first << ' ' << g[i].second << '\n';
	}
	size = l.size();
	cout << size << '\n';
	for (int i = 0;i < size;i++) {
		cout << l[i].first << ' ' << l[i].second << '\n';
	}

}
