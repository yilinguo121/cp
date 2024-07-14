#include<bits/stdc++.h>
using namespace std;
int main() {
	string a[105];
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	string t;
	cin >> t;
	for (int i = n - 1;i >= 0;i--){
		string s;
		int sum = 0;
		for (int j = m - 1;j >= 0;j--) {
			if (a[i][j] == '1'){
				sum++;
			}
			if (a[i][j] == '0'){
				string p;
				p.append(t, j, 1);
				p += s;
				s = p;
			}
			else if (a[i][j] == '1'){
				string p;
				p.append(t, j, 1);
				s += p;
			}
		}
		if (sum % 2 == 1){
			if (s.size() % 2 == 0){
				for (int j = 0;j < m / 2;j++){
					int f = j + (m / 2);
					swap(s[j], s[f]);
				}
			}
			else {
				for (int j = 0;j < m / 2;j++){
					int f = j + (m / 2) + 1;
					swap(s[j], s[f]);
				}
			}
		}
		t = s;
	}
	cout << t;
}
