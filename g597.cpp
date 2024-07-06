#include<bits/stdc++.h>
using namespace std;
#define lint long long
bool cmp (int a ,int b){
	return a > b;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	lint n ,m;
	cin >> n >> m;
	lint ans = 0;
	lint b[200005] = {};
	lint c[200005] = {};
	lint start[200005] = {};
	lint finish[200005] = {};
	lint w[200005] = {};
	for (lint i = 0;i < m;i++){
		cin >> start[i] >> finish[i] >> w[i];
	}
	for (lint i = 0;i < n;i++){
		cin >> b[i];
	}
	sort(b ,b + n);
	for (lint i = 0;i < m;i++){
		c[start[i]] += w[i];
		if (finish[i] + 1 <= n){
			c[finish[i] + 1] -= w[i];
		}
	}
	for (lint i = 1;i <= n;i++){
		c[i] += c[i - 1];
	}
	sort(c ,c + n + 5,cmp);
	for (lint i = 0;i < n;i++){
		ans += c[i] * b[i];
	}
	cout << ans << '\n';
}
