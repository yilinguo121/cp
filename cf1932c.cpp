#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0;i < n;i++) cin >> a[i];
		string s;
		cin >> s;
		int ll = 0, rr = n - 1;
		vector<int> v;
		for (int i = 0;i < n;i++) {
			if (s[i] == 'L') {
				v.push_back(a[ll]);
				ll++;
			}
			else {
				v.push_back(a[rr]);
				rr--;
			}
		}
		reverse(v.begin(), v.end());
		int k = 1;
		vector<int> ans;
		for (int i = 0;i < n;i++) {
			k = k * v[i] % m;
			ans.push_back(k);
		}
		for (int i = n - 1;i > -1;i--) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}
