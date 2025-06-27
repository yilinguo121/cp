#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<array<int, 3>> a, b;
	for (int i = 0;i < n;i++) {
		int x, y, z;
		cin >> x >> y;
		a.push_back({x, y, i});
		b.push_back(a[i]);
	}
	sort(a.begin(), a.end(), [](auto a, auto b) {
		return get<0>(a) < get<0>(b);
	});
	sort(b.begin(), b.end(), [](auto a, auto b) {
		return get<1>(a) < get<1>(b);
	});
	multiset<int> st;
	map<int, set<int>> ans;
	int ans = 0;
	for ()

}

