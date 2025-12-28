#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	multiset<int> a, b;
	while (n--) {
		char t;
		int x;
		cin >> t >> x;
		if (t == '+') {
			if (x >= *b.begin()) b.insert(x);
			else a.insert(x);
		}
		else {
			if (x > *a.rbegin()) b.erase(b.find(x));
			else a.erase(a.find(x));
		}
		int m = a.size() + b.size();
		while (!a.empty() and *a.rbegin() > *b.begin()) {
			b.insert(*a.rbegin());
			a.erase(prev(a.end()));
		}
		while (a.size() > m / 2) {
			b.insert(*a.rbegin());
			a.erase(prev(a.end()));
		}
		while (b.size() > (m + 1) / 2) {
			a.insert(*b.begin());
			b.erase(b.begin());
		}
		cout << (m % 2 ? *b.begin() : (*a.rbegin() + *b.begin()) / 2) << '\n';
	}
}

