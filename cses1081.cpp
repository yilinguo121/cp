#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> cnt(1000001);
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 1000000;i >= 1;i--) {
		int now = 0;
		for (int j = i;j <= 1000000;j += i) {
			now += cnt[j];
		}
		if (now >= 2) {
			cout << i;
			return 0;
		}
	}
}
