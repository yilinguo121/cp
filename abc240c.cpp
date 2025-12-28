#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, x;
	cin >> n >> x;
	set<int> dp;
	dp.insert(0);
	while (n--) {
		int a, b;
		cin >> a >> b;
		set<int> now;
		for (auto t : dp) {
			now.insert(t + a);
			now.insert(t + b);
		}
		dp = now;
	}
	cout << (dp.find(x) == dp.end() ? "No" : "Yes");
}

