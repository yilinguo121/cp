#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string s;
	cin >> s;
	vector<int> pos;
	for (int i = 0;i < s.size();i++) if (s[i] == 't') pos.push_back(i);
	double ans = 0;
	for (int i = 0;i < pos.size();i++) {
		for (int j = i + 1;j < pos.size();j++) {
			if (pos[j] - pos[i] < 2) continue;
			ans = max(ans, 1.0 * (j - i - 1) / (pos[j] - pos[i] - 1));
		}
	}
	cout << fixed << setprecision(17) << ans;
}

