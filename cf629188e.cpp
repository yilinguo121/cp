#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
string s;
int now;
int f();
int mul_div();
int dfs();
int dfs2();
int f() {
	if (s[now] == ')') {
		now--;
		int t = dfs();
		now--;
		return ((t % 7) + 7) % 7;
	}
	else {
		int t = s[now] - '0';
		now--;
		return ((t % 7) + 7) % 7;
	}
}
int mul_div() {
	int t = f();
	while (now >= 0 and s[now] == '-') {
		now--;
		t = (f() % 7) - (t % 7);
	}
	return ((t % 7) + 7) % 7;
}
int dfs2() {
	int t = mul_div();
	while (now >= 0 and s[now] == '+') {
		now--;
		t = (t % 7) + (mul_div() % 7);
	}
	return ((t % 7) + 7) % 7;
}
int dfs() {
	int t = dfs2();
	while (now >= 0 and s[now] == '*') {
		now--;
		t = (t % 7) * (dfs2() % 7);
	}
	return ((t % 7) + 7) % 7;
}
signed main() {
	IO
	cin >> s;
	now = s.size() - 1;
	cout << dfs() % 7;
}
