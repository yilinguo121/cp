#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int cnt[1024] = {};
	cnt[0]++;
	long long ans = 0;
	int t = 0;
	for (int i = 0;i < s.size();i++) {
		t ^= (1 << (s[i] - '0'));
		ans += cnt[t];
		cnt[t]++;
	}
	cout << ans;
}

