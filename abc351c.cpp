#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	deque<int> v;
	int r;
	cin >> r;
	v.push_back(r);
	for (int i = 1;i < n;i++) {
		int t;
		cin >> t;
		v.push_back(t);
		while (v.size() > 1 and v[v.size() - 1] == v[v.size() - 2]) {
			t = v[v.size() - 1] + 1;
			v.pop_back();
			v.pop_back();
			v.push_back(t);
		}
	}
	cout << v.size();
}
