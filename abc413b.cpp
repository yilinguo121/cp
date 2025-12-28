#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	set<string> st;
	vector<string> s(n);
	for (auto &x : s) cin >> x;
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) if (i != j) st.insert(s[i] + s[j]);
	cout << st.size();
}

