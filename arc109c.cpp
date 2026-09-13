#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
char win(char a, char b) {
	if (a == b) return a;
	if ((a == 'R' and b == 'S') or (a == 'P' and b == 'R') or (a == 'S' and b == 'P')) return a;
	return b;
}
int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<char> v(s.begin(), s.end()), nxt(n);
	int add = 1 % n;
	while (k--) {
		for (int i = 0;i < n;i++) nxt[i] = win(v[i], v[(i + add) % n]);
		v.swap(nxt);
		add = (add * 2) % n;
	}
	cout << v[0];
}

