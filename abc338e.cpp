#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<pair<int, bool>> v(2 * n);
	for (int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v[min(a, b)] = {i, 0};
		v[max(a, b)] = {i, 1};
	}
	vector<int> st;
	for (auto [pos, x] : v) {
		if (x) {
			if (st.back() != pos) {
				cout << "Yes";
				return 0;
			}
			else st.pop_back();
		}
		else st.push_back(pos);
	}
	cout << "No";
}

