#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<pair<int, int>> p;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++) {
		while(a[i] != i) {
			p.push_back({i, a[i]});
			swap(a[i], a[a[i]]);
		}
	}
	int s = p.size();
	cout << s << '\n';
	if (s) {
		for (int i = 0;i < s;i++) {
			cout << p[i].first << ' ' << p[i].second << '\n';
		}
	}

}
