#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0;i < n;i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end(), cmp);
		long long alice = 0, bob = 0;
		for (int i = 0;i < n;i++) {
			if (i % 2) {
				if (v[i] % 2) bob += v[i];
			}
			if (i % 2 == 0) {
				if (v[i] % 2 == 0) alice += v[i];
			}
		}
		if (alice > bob) cout << "Alice\n";
		else if (alice < bob) cout << "Bob\n";
		else cout << "Tie\n";
	}
}

