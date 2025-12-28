#include<bits/stdc++.h>
using namespace std;
bool cmp (pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
	if (a.first.first == b.first.first) return a.first.second > b.first.second;
	return a.first.first > b.first.first;
}
bool cmp2 (pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
	return a.second.first < b.second.first;
}
int main() {
	int n;
	cin >> n;
	int a[n][5], sum[n] = {}, mx[n] = {};
	vector<pair<pair<int, int>, pair<int, int>>> v(n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> a[i][j];
			sum[i] += a[i][j];
			if (a[i][j] == 100) mx[i]++;
			v[i].first.first = sum[i];
			v[i].first.second = mx[i];
			v[i].second.first = i;
		}
	}
	sort(v.begin(), v.end(), cmp);
	v[0].second.second = 1;
	int t = 1, m = 1;
	for (int i = 1;i < n;i++) {
		if (v[i].first.first == v[i - 1].first.first and v[i].first.second == v[i - 1].first.second) {
			v[i].second.second = t;
		}
		else {
			t += m;
			m = 0;
			v[i].second.second = t;
		}
		m++;
	}
	sort(v.begin(), v.end(), cmp2);
	for (int i = 0;i < n;i++) {
		cout << v[i].second.second << '\n';
	}
}
