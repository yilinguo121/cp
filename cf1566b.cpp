#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		int ans = 0;
		bool f = 0;
		for (int i = 0;i < s.size();i++) {
			if (s[i] == '0' and f == 0) {
				ans++;
				f = 1;
			}
			if (s[i] == '1') {
				f = 0;
			}
		}
		ans = min(ans, 2);
		cout << ans << '\n';
	}
}
