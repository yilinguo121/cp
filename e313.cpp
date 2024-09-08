#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s[n];
	int cnt = 1005;
	string ans;
	for (int i = 0;i < n;i++) {
		set<int> st;
		cin >> s[i];
		for (int j = 0;j < s[i].size();j++) {
			st.insert(s[i][j]);
		}
		if (st.size() == cnt) {
			ans = min(ans, s[i]);
		}
		else if (st.size() < cnt) {
			cnt = st.size();
			ans = s[i];
		}
	}
	cout << ans;
}
