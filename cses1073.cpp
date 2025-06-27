#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	multiset<int> ans;
	while (n--) {
		int x;
		cin >> x;
		auto it = ans.upper_bound(x);
		if (it == ans.end()) ans.insert(x);
		else {
			ans.erase(it);
			ans.insert(x);
		}
	}
	cout << ans.size();
}
