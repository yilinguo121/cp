#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> ans;
	while (n--) {
		int x;
		cin >> x;
		if (ans.empty() or x > ans.back()) ans.push_back(x);
		else *lower_bound(ans.begin(), ans.end(), x) = x;
	}
	cout << ans.size();
}
