#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int a[n] = {}, v[n] = {};
		for (int i = 0;i < n;i++) {
			cin >> a[i];
			a[i]--;
		}
		int lc = 1;
		for (int i = 0;i < n;i++) {
			if (v[i]) continue;
			string k;
			int pos = i;
			while (v[pos] == 0) {
				k += s[pos];
				v[pos] = 1;
				pos = a[pos];
			}
			for (int i = 1;;i++) {
				bool flag = 0;
				for (int j = i;j - i < k.size();j++) {
					if (k[j % k.size()] != k[j - i]) {
						flag = 1;
						break;
					}
				}
				if (!flag) {
					lc = lcm(lc, i);
					break;
				}
			}
		}
		cout << lc << '\n';
	}
}
