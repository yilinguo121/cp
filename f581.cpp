#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int p[n + 1];
	for (int i = 1;i <= n;i++) {
		cin >> p[i];
	}
	vector<int> v;
	v.push_back(0);
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		sum += p[i];
		v.push_back(sum);
	}
	for (int i = 1;i <= n;i++) {
		sum += p[i];
		v.push_back(sum);
	}
	int s = 1, t;
	while (m--) {
		int x;
		cin >> x;
		t = lower_bound(v.begin(), v.end(), x + v[s - 1]) - v.begin();
		t = t % n + 1;
		s = t;
	}
	cout << t - 1;
}
