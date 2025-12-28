#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
string s;
vector<int> p;
void dfs(int l, int r, bool flag) {
	if (l > r) return;
	if (flag) {
		for (int i = r;i >= l;i--) {
			if (p[i] == -1) cout << (char)(s[i] ^ (1 << 5));
			else {
				dfs(p[i] + 1, i - 1, !flag);
				i = p[i];
			}
		}
	}
	else {
		for (int i = l;i <= r;i++) {
			if (p[i] == -1) cout << s[i];
			else {
				dfs(i + 1, p[i] - 1, !flag);
				i = p[i];
			}
		}
	}
}
int main() {
	cin >> s;
	p.assign(s.size(), -1);
	vector<int> v;
	for (int i = 0;i < s.size();i++) {
		if (s[i] == '(') v.push_back(i);
		if (s[i] == ')'){
			p[i] = v.back();
			p[v.back()] = i;
			v.pop_back();
		}
	}
	dfs(0, s.size() - 1, 0);
}

