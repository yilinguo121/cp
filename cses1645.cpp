#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> v, a(n + 1);
	v.push_back(0);
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		while (v.size() > 1 and a[i] <= a[v.back()]) v.pop_back();
		cout << v.back() << ' ';
		v.push_back(i);
	}
}

