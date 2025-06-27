#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	sort(v.begin(), v.end());
	double l = 0, r = *max_element(v.begin(), v.end());
	for (int i = 0;i < 60;i++) {
		double m = (l + r) / 2;
		int cnt = 0;
		for (auto x : v) cnt += (int)(1.0 * x / m);
		if (cnt >= k) l = m;
		else r = m;
	}
    cout << fixed << setprecision(15) << (l + r) / 2 << '\n';
}
