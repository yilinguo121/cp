#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
struct type {
	int sum;
	int head;
	int end;
};
int i = 0;
string s;
type dfs() {
	type t{0, -1, -1};
	while (i < s.size()) {
		if (s[i] == 'T') {
			int d = ((s[i + 1] - '0') * 10 + s[i + 2] - '0');
			if (t.head == -1) t.head = d;
			else t.sum += abs(t.end - d);
			t.end = d;
			i += 3;
		}
		if (s[i] == 'L') {
			int k = s[i + 1] - '0';
			i += 2;
			auto x = dfs();
			if (t.head == -1) t.head = x.head;
			else t.sum += abs(t.end - x.head);
			t.sum += x.sum * k + abs(x.head - x.end) * (k - 1);
			t.end = x.end;
		}
		if (s[i] == 'E') {
			i++;
			break;
		}
	}
	return t;
}
signed main() {
	IO
	cin >> s;
	auto v = dfs();
	cout << v.sum + abs(10 - v.head);
}

