#include<bits/stdc++.h>
using namespace std;
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	string s[25];
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	int a = m - 1;
	int b = 0;
	int x[6] = {-1, 0, 1, 1, 0, -1};
	int y[6] = {0, 1, 1, 0, -1,-1};
	vector<char> v;
	set<char> st;
	for (int i = 0; i < k; i++) {
		int j;
		cin >> j;
		if (a + x[j] < 0 or a + x[j] >= m or b + y[j] < 0 or b + y[j] >= n){
			v.push_back(s[a][b]);
			st.insert(s[a][b]);
		}else {
			a += x[j];
			b += y[j];
			v.push_back(s[a][b]);
			st.insert(s[a][b]);
		}
	}
	for (int i = 0; i < v.size(); i++){
		cout << v[i];
	}
	cout << '\n';
	cout << st.size() << '\n';
}
