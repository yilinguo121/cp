#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	queue<char> q;
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	int mp1[26] = {}, mp2[26] = {};
	for (auto x : b) mp2[x - 'a']++;
	int cnt = 0, qc = 0, ans = 0;
	for (int i = 0;i < n;i++) {
		char c = a[i];
		if (c == '?') qc++;
		else mp1[c - 'a']++;
		q.push(c);
		while (q.size() > m) {
			if (q.front() == '?') qc--;
			else mp1[q.front() - 'a']--;
			q.pop();
		}
		if (q.size() == m) {
			cnt = 0;
			for (char j = 'a';j <= 'z';j++) {
				cnt += min(mp1[j - 'a'], mp2[j - 'a']);
			}
			if (cnt + qc == m) ans++;
		}
	}
	cout << ans;
}

