#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (int j = 0;j < n;j++) cin >> v[j];
		sort(v.begin(), v.end());
		for (auto x : v) cout << x << ' ';
		cout << '\n';
	}
}

