#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector<char> ans;
		for (auto x : s) {
			if (x == 'T') cout << 'T';
			else ans.push_back(x);
		}
		for (auto x : ans) cout << x;
		cout << '\n';
	}
}

