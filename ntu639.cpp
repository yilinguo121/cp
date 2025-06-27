#include <bits/stdc++.h>
using namespace std;
string s;
int ans, pos;
void f(int n) {
	if (s[pos] == '1') ans += n * n;
	if (s[pos] == '2') {
		for (int i = 0;i < 4;i++) {
			pos++;
			f(n / 2);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> s >> n;
	f(n);
	cout << ans;
}

