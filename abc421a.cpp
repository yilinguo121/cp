#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	string s[n + 1];
	for (int i = 1;i <= n;i++) cin >> s[i];
	int a;
	string b;
	cin >> a >> b;
	cout << (b == s[a] ? "Yes" : "No");
}

