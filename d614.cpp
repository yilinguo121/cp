#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		int ans = 0;
		string s;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> s) {
			if (s != "+") ans += stoi(s);
		}
		cout << ans << '\n';
	}
}

