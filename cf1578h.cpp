#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int i = 0;
string s;
int dfs1();
int dfs2();
int dfs1() {
	int x = dfs2();
	if (s[i] == '-') {
		i += 2;
		return max(x + 1, dfs1());
	}
	return x;
}
int dfs2() {
	if (s[i] == '(') {
		if (s[i + 1] == ')') {
			i += 2;
			return 0;
		}
		i++;
		int x = dfs1();
		i++;
		return x;
	}
}
int main() {
	IO
	cin >> s;
	cout << dfs1();
}

