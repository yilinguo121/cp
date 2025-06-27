#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, q;
	string s;
	cin >> n >> q >> s;
	vector<vector<int>> v(2, vector<int>(n + 1, -1));
	for (int i = n - 1;i >= 0;i--) {
		v[0][i] = v[0][i + 1];
		v[1][i] = v[1][i + 1];
		v[s[i] - '0'][i] = i;
	}
	while (q--) {
		string t;
		cin >> t;
		int j = 0;
		for (auto c : t) {
			if (v[c - '0'][j] == -1) {
				j = -1;
				break;
			}
			j = v[c - '0'][j] + 1;
		}
		cout << j << '\n';
	}
}

