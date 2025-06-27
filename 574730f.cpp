#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v(16);
int ans = 20;
void f(multiset<long long> st, set<int> a, int pos) {
	if (pos == 16) {
		int sz = a.size();
		ans = min(ans, sz);
	}
	else {
		st.insert(v[pos]);
		f(st, pos + 1);
		st.erase(st.find(v[pos]));
		st.insert()
		
	}
}
int main() {
	cin >> n;
	for (int i = 0;i < n;i++) cin >> v[i];
	multiset<long long> st;
	set<int> a;
	f(st, a, 0);
	cout << ans;
}

