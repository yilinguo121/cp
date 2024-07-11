#include<bits/stdc++.h>
using namespace std;
#define int long long
#define t first
#define w second
bool cmp(pair<int ,int> a, pair<int ,int> b){
	int p = a.t * a.w + (a.t + b.t) * b.w;
	int q = b.t * b.w + (b.t + a.t) * a.w;
	return p < q;
}
signed main(){
	int n;
	cin >> n;
	vector <pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].t;
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i].w;
	}
	sort (v.begin(), v.end(), cmp);
	int now = 0,ans = 0;
	for (int i = 0; i < n; i++) {
		now += v[i].t;
		ans += now * v[i].w;
	}
	cout << ans << '\n';
}
