#include<bits/stdc++.h>
using namespace std;
int f(int n, vector<int> v) {
	int ans = 0;
	for (int i = 0;i < n - 1;i++) {//0 1 2
		if (v[i] > v[i + 1]) {//v[0] = 4 v[1] = 3 v[2] = 2 v[3] = 1
			ans++;
			i++;
		}
	}
	return ans;
}
int main() {
	int t;
	cin >> t;
	for (int j = 0;j < t;j++) {
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 0;i < n;i++) {
			int k;
			cin >> k;
			v.push_back(k);
		}
		cout << f(n, v) << '\n';
	}
}
