#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	set<set<int>> s;
	int a[n] = {};
	for (int i = 0;i < n;i++) {
		if (a[i] != 0) {
			continue;
		}
		set<int> st;
		if (v[i] == i) {
			st.insert(i);
		}else {
			int t = i;
			while(1) {
				if (st.find(i) != st.end()) {
					break;
				}
				st.insert(v[t]);
				a[t]++;
				t = v[t];
			}
		}
		s.insert(st);
	}
	cout << s.size();
}
