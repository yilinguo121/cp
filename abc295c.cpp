#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	map<int, int> mp;
	int ans = 0;
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		mp[t]++;
		if (mp[t] % 2 == 0) {
			ans++;
		}
	}
	cout << ans;
}
