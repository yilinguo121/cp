#include<bits/stdc++.h>
using namespace std;
#define D double
#define x first
#define y second
signed main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(m);
	for (int i = 0;i < m;i++){
		cin >> v[i].x >> v[i].y;
	}
	D ans = 999999,sum = 999999;
	for (int i = 0;i < m;i++){
		for (int j = 0;j < m;j++){
			if (i == j){
				continue;
			}
			sum = pow(pow(v[i].x - v[j].x, 2) + pow(v[i].y - v[j].y, 2), 0.5);
			ans = min(ans, sum);
		}
	}
	cout << fixed << setprecision(4) << ans << '\n';
}
