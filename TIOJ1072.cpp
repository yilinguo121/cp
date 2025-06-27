#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
bool cmp(pair<int, int> a, pair<int, int> b){
	return a.s > b.s;
}
int main(){
	int n;
	while (cin >> n){
		if (n == 0){
			break;
		}
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].f >> v[i].s;
		}
		sort(v.begin(), v.end(), cmp);
		int ans = 0 ,t = 0;
		for (int i = 0; i < n; i++) {
			t = t - v[i].f;
			t = max(0 ,t);
			ans += v[i].f;
			t = max(t ,v[i].s);
		}
		ans += t;
		cout << ans << '\n';
	}
}

