#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, x;
	cin >> n >> x;
	set<int> st;
	vector<int> v;
	for (int i = 1;i <= n;i++) {
		int t;
		cin >> t;
		if (st.find(x - t) != st.end()){
			for (int j = 0;j < v.size();j++){
				if (v[j] == x - t){
					cout << j + 1 << ' ';
					break;
				}
			}
			cout << i;
			return 0;
		}
		st.insert(t);
		v.push_back(t);
	}
	cout << "IMPOSSIBLE";
}
