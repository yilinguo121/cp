#include <bits/stdc++.h>
using namespace std;
int main() {
	int w, h;
	cin >> w >> h;
	int n;
	cin >> n;
	int p[n], q[n];
	for (int i = 0;i < n;i++) cin >> p[i] >> q[i];
	int A, B;
	cin >> A;
	vector<int> a(A);
	for (int i = 0;i < A;i++) cin >> a[i];
	a.push_back(w);
	cin >> B;
	vector<int> b(B);
	for (int i = 0;i < B;i++) cin >> b[i];
	b.push_back(h);
	map<pair<int, int>, int> mp;
	for (int i = 0;i < n;i++) mp[{upper_bound(a.begin(), a.end(), p[i]) - a.begin(), upper_bound(b.begin(), b.end(), q[i]) - b.begin()}]++;
	int MAX = 0, MIN = 1e9;
	for (auto x : mp) {
		MAX = max(MAX, x.second);
		MIN = min(MIN, x.second);
	}
	if (mp.size() < (A + 1) * (B + 1)) MIN = 0;
	cout << MIN << ' ' << MAX;

}

