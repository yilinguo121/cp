#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	multiset<int> st;
	while (n--) {
		int x;
		cin >> x;
		st.insert(x);
	}
	while (m--) {
		int x;
		cin >> x;
		auto it = st.find(x);
		if (it != st.end()) st.erase(it);
	}
	for (auto x : st) cout << x << ' ';
}

