#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, l;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i < n;i++) cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for (int i = 0;i < m;i++) cin >> b[i];
	cin >> l;
	vector<int> c(l);
	for (int i = 0;i < l;i++) cin >> c[i];
	vector<int> v(n * m * l);
	int t = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			for (int k = 0;k < l;k++) {
				v[t] = a[i] + b[j] + c[k];
				t++;
			}
		}
	}
	sort(v.begin(), v.end());
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (binary_search(v.begin(), v.end(), x)) cout << "Yes\n";
		else cout << "No\n";
	}

}

