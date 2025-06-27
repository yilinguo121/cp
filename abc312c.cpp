#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	for (int i = 0;i < m;i++) {
		int t;
		cin >> t;
		v.push_back(t + 1);
	}
	sort(v.begin(), v.end());
	cout << v[m - 1];
}
