#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	string s;
	cin >> s;
	map<char, int> mp;
	int cnt = 0;
	int l = -1, r = 1e9;
	for (int i = 0, j = 0;i < s.size();i++) {
		if (!mp[s[i]]) cnt++;
		mp[s[i]]++;
		while (mp[s[j]] > 1) {
			mp[s[j]]--;
			if (!mp[s[j]]) cnt--;
			j++;
		}
		if (cnt == 26 and r - l > i - j) {
			r = i;
			l = j;
		}
	}
	if (l == -1) cout << "QQ";
	else {
		for (int i = l;i <= r;i++) cout << s[i];
	}
}

