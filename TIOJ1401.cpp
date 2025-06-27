#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
bool cmp1(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	return get<0>(a) < get<0>(b);
}
bool cmp2(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	return get<2>(a) < get<2>(b);
}
int main() {
	IO
	int n;
	while (cin >> n) {
		vector<tuple<int, int, int, int>> v(n);
		for (auto &[a, b, c, d] : v) cin >> a >> b >> c >> d;
		sort(v.begin(), v.end(), cmp1);
		priority_queue<int, vector<int>, greater<int>> q;
		int now = 0, pos = 0;
		bool flag = 1;
		while (pos < n or !q.empty()) {
			now++;
			if (q.empty()) now = max(now, get<0>(v[pos]));
			while (pos < n and get<0>(v[pos]) <= now) {
				q.push(get<1>(v[pos]));
				pos++;
			}
			if (!q.empty() and q.top() < now) {
				cout << "NO\n";
				flag = 0;
				break;
			}
			if (!q.empty()) q.pop();
		}
		if (!flag) continue;
		sort(v.begin(), v.end(), cmp2);
		while (!q.empty()) q.pop();
		now = 0, pos = 0;
		while (pos < n or !q.empty()) {
			now++;
			if (q.empty()) now = max(now, get<2>(v[pos]));
			while (pos < n and get<2>(v[pos]) <= now) {
				q.push(get<3>(v[pos]));
				pos++;
			}
			if (!q.empty() and q.top() < now) {
				cout << "NO\n";
				flag = 0;
				break;
			}
			if (!q.empty()) q.pop();
		}
		if (flag) cout << "YES\n";
	}
}

