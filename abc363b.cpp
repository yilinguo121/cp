#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, t, p;
	cin >> n >> t >> p;
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	if (v[p - 1] >= t) {
		cout << 0;
	}else {
		cout << t - v[p - 1];
	}
}
