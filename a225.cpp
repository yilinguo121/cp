#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
	if (a % 10 == b % 10) return a > b;
	return a % 10 < b % 10;
}
int main() {
	int n;
	while(cin >> n) {
		vector<int> v(n);
		for (int i = 0;i < n;i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end(), cmp);
		for (auto x : v) cout << x << ' ';
		cout << '\n';
	}
}
