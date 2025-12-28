#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, k;
	cin >> n >> k;
	multiset<int> a, b;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	for (int i = 0;i < k;i++) b.insert(v[i]);
	for (int i = 0;i < k / 2 + k % 2;i++) {
		a.insert(*b.begin());
		b.erase(b.begin());
	}
	for (int i = k;i < n;i++) {
		cout << *a.rbegin() << ' ';
		if (a.find(v[i - k]) == a.end()) b.erase(b.find(v[i - k]));
		else a.erase(a.find(v[i - k]));
		if (a.empty() or v[i] >= *a.rbegin()) b.insert(v[i]);
		else a.insert(v[i]);
		while (b.size() > k / 2) {
			a.insert(*b.begin());
			b.erase(b.begin());
		}
		while (b.size() < k / 2) {
			b.insert(*a.rbegin());
			a.erase(prev(a.end()));
		}
	}
	cout << *a.rbegin();
}
