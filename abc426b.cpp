#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string s;
	cin >> s;
	int cnt[26] = {};
	for (auto x : s) {
		cnt[x - 'a']++;
	}
	for (int i = 0;i < 26;i++) if (cnt[i] == 1) cout << (char)(i + 'a');
}
