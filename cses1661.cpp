#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, x;
	map<long long, int> mp;
	cin >> n >> x;
	vector<long long> v(n + 1);
	mp[0] = 1;
	long long ans = 0;
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		v[i] += v[i - 1];
		if (mp.find(v[i] - x) != mp.end()) ans += mp[v[i] - x];
		mp[v[i]]++;
	}
	cout << ans;

}

