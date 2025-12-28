#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int now = 0;
string s;
int dfs();
int sum();
int f();
int dfs() {
	int t = sum();
	while (now < s.size() and s[now] == '*') {
		now++;
		t *= sum();
	}
	return t;
}
int sum() {
	int t = f();
	while (now < s.size() and s[now] == '+') {
		now++;
		t += f();
	}
	return t;
}
int f() {
	if (s[now] >= '0' and s[now] <= '9') {
		int t = 0;
		while (now < s.size() and s[now] >= '0' and s[now] <= '9') {
			t = t * 10 + s[now] - '0';
			now++;
		}
		return t;
	}
	now += 2;
	vector<int> v;
	while(1) {
		v.push_back(dfs());
		if (s[now] == ',') now++;
		else break;
	}
	now++;
	return *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
}
signed main() {
	IO
	cin >> s;
	cout << dfs();
}
