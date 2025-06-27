#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	vector<long long> v(s.size());
	for (int i = 1;i < s.size();i++) {
		if (s[i] == 'v' and s[i - 1] == 'v') v[i]++;
		v[i] += v[i - 1];
	}
	long long ans = 0;
	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'o' and i >= 2 and i <= s.size() - 3) {
			ans += (v[i] - v[0]) * (v[v.size() - 1] - v[i]);
		}
	}
	cout << ans;
}

