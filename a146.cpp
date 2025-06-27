#include<bits/stdc++.h>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	while (cin >> n >> k) {
		vector<int> v(n), a, b;
		k = min(n, k);
		for (int i = 0;i < n;i++) {
			cin >> v[i];
		}
		multiset<int> st;
		for (int i = 0;i < k;i++) {
			st.insert(v[i]);
		}
		a.push_back(*st.begin());
		b.push_back(*--st.end());
		for (int i = k;i < n;i++) {
			st.erase(st.find(v[i - k]));
			st.insert(v[i]);
			a.push_back(*st.begin());
			b.push_back(*--st.end());
		}
		for (int i = 0;i < a.size() - 1;i++) {
			cout << a[i] << ' ';
		}
		cout << a[a.size() - 1];
		cout << '\n';
		for (int i = 0;i < b.size() - 1;i++) {
			cout << b[i] << ' ';
		}
		cout << b[b.size() - 1];
		cout << '\n';
		
	}
}
