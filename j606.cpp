#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
bool cmp(pair<char, int> a, pair<char, int> b) {
	return a.S < b.S;
}
int main() {
	int k, q, r;
	cin >> k >> q >> r;
	string s;
	cin >> s;
	vector<pair<char, int>> v(k);
	vector<string> a;
	for (int i = 0;i < k;i++) {
		v[i].F = s[i];
	}
	for (int i = 0;i < q;i++) {
		for (int j = 0;j < k;j++){
			int t;
			cin >> t;
			v[j].S = t;
		}
		sort(v.begin(), v.end(), cmp);
		for (int j = 0;j < k;j++) {
			s[j] = v[j].F;
		}
		a.push_back(s);
	}
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < q;j++) {
			cout << a[j][i];
		}
		cout << '\n';
	}

}
