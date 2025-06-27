#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<pair<int, pair<int, int>>> v;
	int t = 1;
	int l = -1, r = -1;
	for (int i = 0;i < n;i++) {
		if(t - 1 == k) break;
		if (s[i] == '1' and (l == -1 or s[i - 1] == '0')) {
			l = i;
		}
		if (s[i] == '0' and (l != -1 or s[i - 1] == '1')) {
			r = i - 1;
			v.push_back({t, {l, r}});
			r = -1;
			l = -1;
			t++;
		}
	}
	if(r == -1 and l != -1) v.push_back({t, {l, n - 1}});
	k--;
	for (int i = 0;i < n;i++) {
		if (i == v[k - 1].second.first) {
			for (int i = v[k].second.first;i <= v[k].second.second;i++) cout << 1;
		}
		if (i >= v[k].second.first and i <= v[k].second.second) continue;
		else cout << s[i];
	}
	
}

