#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
bitset<10000001> v = {};
int mp[10000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	bool one = 1;
	while (n--) {
		int x;
		cin >> x;
		mp[x]++;
		if (x != 1) one = 0;
	}
	if (one) cout << 1;
	else {
		bool first = 1;
		for (int i = 2;i <= 10000000;i++) {
			if (!v[i]) {
				long long pow = 0;
				for (int j = i;j <= 10000000;j += i) {
					v[j] = 1;
					int t = j;
					while (t % i == 0) {
						t /= i;
						pow += mp[j];
					}
				}
				if (pow) {
					if (!first) cout << '*';
					else first = 0;
					cout << i << '^' << pow;
				}
			}
		}
	}
}
