#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	string ss;
	deque<char> s; // 不能用string會tle
	cin >> ss;
	bool flag = 0;
	for (auto x : ss) {
		if (x == 'R') {
			flag = !flag;
			continue;
		}
		if (!flag) s.push_back(x);
		else s.push_front(x);
	}
	vector<char> v;
	while (!s.empty()) {
		auto x = s.front();
		s.pop_front();
		if (v.size() >= 1 and x == v[v.size() - 1]) v.pop_back();
		else v.push_back(x);
	}
	if (flag) {
		for (int i = v.size() - 1;i >= 0;i--) cout << v[i];
	}
	else {
		for (auto x : v) cout << x;
	}
}

