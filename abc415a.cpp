#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int x;
	cin >> x;
	for (auto t : v) {
		if (t == x) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}

