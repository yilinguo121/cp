#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	vector<int> v(n + 1), ans(n + 1), st;
	for (int i = 1;i <= n;i++) cin >> v[i];
	for (int i = n;i >= 1;i--) {
		while (!st.empty() and v[st.back()] < v[i]) st.pop_back();
		st.push_back(i);
		ans[i - 1] = st.size();
	}
	for (int i = 1;i <= n;i++) cout << ans[i] << ' ';
}

