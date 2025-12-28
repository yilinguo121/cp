#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string s;
	int a, b;
	cin >> a >> a >> b >> s;
	for (int i = 1;i <= s.size();i++) {
		if (i > a and i <= s.size() - b) cout << s[i - 1];
	}
}

