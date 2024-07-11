#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp (int a, int b){
	return a > b;
}
signed main(){
	int n ,m;
	cin >> n >> m;
	vector<int> v(n + 5), a;
	for (int i = 0; i < m; i++) {
		int s, f, l;
		cin >> s >> f >> l;
		v[s] += l;
		v[f + 1] -= l;
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		a.push_back(k);
	}
	sort(a.begin(), a.end());
	int now = 0;
	for (int i = 1; i < v.size(); i++) {
		v[i] += v[i - 1];
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	for (int i = 0; i < a.size(); i++){
		ans += (v[i] * a[i]);
	}
	cout << ans << '\n';
}
