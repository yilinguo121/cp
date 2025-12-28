#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1), a(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		a[i] = v[i];
		v[i] += v[i - 1];
	}
	if (k == 1) {
		cout << *max_element(a.begin(), a.end());
		return 0;
	}
	if (*max_element(a.begin(), a.end()) == 1) {
		int cnt = 0, sum = 0;
		for (int i = 1;i <= n;i++) {
			if (a[i]) cnt++;
			else {
				sum += cnt * (cnt - 1) / 2;
				cnt = 0;
			}
		}
		cout << (sum < k ? 0 : 1);
		return 0;
	}
	priority_queue<int> q;
	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			q.push((v[j] - v[i - 1]) / (j - i + 1));
		}
	}
	k--;
	while (k--) q.pop();
	cout << q.top();
}
