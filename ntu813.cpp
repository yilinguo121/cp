#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	v.push_back(x);
	sort(v.begin(), v.end());

}

